/*
 * StudentsToProjects.cpp
 *
 *  Created on: Oct 30, 2019
 *      Author: sean
 */

#include "StudentsToProjects.h"
#include <iostream>
#include <vector>
#include <thread>
#include <array>
#include <chrono>
#include <algorithm>
#include <fstream>
#include "json/json.h"
using namespace std;
using namespace std::chrono;

StudentsToProjects::StudentsToProjects() {

}
constexpr int StudentsToProjects::toConstInt(int constInt) {
	return constInt;
}


void StudentsToProjects::StudentsToProjectsAssignment(Student StudentList[], Project ProjectList[],int numProjects,int numStudents) {


    auto start = high_resolution_clock::now();
	srand(time(NULL));


	int numSkills = 7;
	int teamSize = 5;
	const int NUM_PROJECTS = toConstInt(numProjects);

	struct Team {

				Student Team[5];
				int TeamScore;
			};

    struct ProjectSet {

				//Team Teams[NUM_PROJECTS];
				int ProjectSetScore;
			};

	Team currentTeam;
	ProjectSet currentSet, bestSet, bestSetWithDuplicates;

   //used to store the top 10 teams for every project.

	Team temp;
	Team currentTopTeams[10];
	 for(int j = 0; j < 10; j++) {
			 currentTopTeams[j]=temp;
		 }

	Team topTeams[NUM_PROJECTS][10];

    int top1 = 0;
    int top2 = 0;
    int top3 = 0;
    int top4 = 0;
    int top5 = 0;
    int top6 = 0;
    int top7 = 0;
    int top8 = 0;
    int top9 = 0;
    int top10 = 0;

	//calculate each team combination skillscore for each project
	int teamskillscore = 0;
    int num =0;

	cout << "STUDENTS TO PROJECTS ASSIGNMENT RUNNING..." << endl;
	for(int i = 0; i < numProjects; i++) {

		string bitmask(teamSize,1);
		bitmask.resize(numStudents, 0);
		while(std::prev_permutation(bitmask.begin(), bitmask.end())) {
			for (int j = 0; j < numStudents; ++j) {
				if(bitmask[j]) {

					currentTeam.Team[num] = StudentList[j];
					num++;
					//for(int k = 0; k < numSkills; k++) {
					//	teamskillscore += StudentList[j].Skills[k] * ProjectList[i].Skills[k];
					//}
				}
			} //end j loop

			//negative affinity check

			//call to 3 team score functions
			//TeamScore = func1() + func2() + func3()
             num=0;
			 int score1 = ProjectCompareTeamScore(currentTeam.Team,  ProjectList[i]);
			 int score2 = SkillCompareTeamScore(currentTeam.Team);
			 int score3 = AvailabilityTeamScore(currentTeam.Team);

			teamskillscore = score1 + score2 + score3;

			currentTeam.TeamScore = teamskillscore;
			//debugging: cout for seeing the teamscores.
			//cout << "TeamScore: "+ to_string(score1) +" " + to_string(score2) +" " + to_string(score3) +" " << " = " << teamskillscore <<endl;

			if (currentTeam.TeamScore > top1 ){
				top1 = currentTeam.TeamScore;
				currentTopTeams[0] = currentTeam;
			}else if ( currentTeam.TeamScore == top1 | currentTeam.TeamScore > top2 ){
				top2 = currentTeam.TeamScore;
				currentTopTeams[1] = currentTeam;
			}else if ( currentTeam.TeamScore == top2 | currentTeam.TeamScore > top3 ){
				top3 = currentTeam.TeamScore;
				currentTopTeams[2] = currentTeam;
			}else if ( currentTeam.TeamScore == top3 | currentTeam.TeamScore > top4 ){
				top4 = currentTeam.TeamScore;
				currentTopTeams[3] = currentTeam;
			}else if ( currentTeam.TeamScore == top4 | currentTeam.TeamScore > top5 ){
				top5 = currentTeam.TeamScore;
				currentTopTeams[4] = currentTeam;
			}else if ( currentTeam.TeamScore == top5 | currentTeam.TeamScore > top6 ){
				top6 = currentTeam.TeamScore;
				currentTopTeams[5] = currentTeam;
			}else if ( currentTeam.TeamScore == top6 | currentTeam.TeamScore > top7 ){
				top7 = currentTeam.TeamScore;
				currentTopTeams[6] = currentTeam;
			}else if ( currentTeam.TeamScore == top7 | currentTeam.TeamScore > top8 ){
				top8 = currentTeam.TeamScore;
				currentTopTeams[7] = currentTeam;
			}else if ( currentTeam.TeamScore == top8 | currentTeam.TeamScore > top9 ){
				top9 = currentTeam.TeamScore;
				currentTopTeams[8] = currentTeam;
			}else if ( currentTeam.TeamScore == top9 | currentTeam.TeamScore > top10 ){
				top10 = currentTeam.TeamScore;
				currentTopTeams[9] = currentTeam;}

			teamskillscore = 0;
			/*Student temp;
			//reset team
				 for(int k = 0; k < 5; k++) {
						 currentTeam.Team[k]=temp;
					 }*/

			currentTeam.TeamScore = 0;

		}// end while loop

		 for(int j = 0; j < 10; j++) {

		 topTeams[i][j] = currentTopTeams[j];
		 }
            top1 = 0;
            top2 = 0;
            top3 = 0;
            top4 = 0;
            top5 = 0;
            top6 = 0;
            top7 = 0;
            top8 = 0;
            top9 = 0;
            top10 = 0;

		cout << "Project # " + to_string(ProjectList[i].ProjectID) + "  team combinations complete. " << endl;

	} // end i loop


	// Do Project Set combinations here
	// End Project Set combinations


	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "time in milliseconds: ";
	cout << duration.count() << endl;
	//cout << "Number of iterations: ";
	cout << endl;
	cout<< "Top 10 teams for each project"<<endl;


	for(int i = 0; i < numProjects; i++) {

		cout<< "Projects #" + to_string(ProjectList[i].ProjectID) + " Student Teams:"<<endl;
		for(int j = 0; j < 10; j++) {

		  cout << "Team #" + to_string(j) + " ";
		  for(int k = 0; k < teamSize; k++) {

			 cout<< to_string(topTeams[i][j].Team[k].StudentID) + " ";

		  }
		  cout << endl;
		  cout<< "TeamScore: " + to_string(topTeams[i][j].TeamScore)<<endl;
		}
		 cout << endl;
	}

}

//Team Score Calculating Functions

// This function returns a score of 0-20 determining
// the quality of the team by comparing the Availability of students
// on a team to each other.
int StudentsToProjects::AvailabilityTeamScore(Student team[5]){

	int timeCompareScore = 0;

	timeCompareScore += StudentToStudentAvailibility(team[0], team[1]);
	timeCompareScore += StudentToStudentAvailibility(team[0], team[2]);
	timeCompareScore += StudentToStudentAvailibility(team[0], team[3]);
	timeCompareScore += StudentToStudentAvailibility(team[0], team[4]);
	timeCompareScore += StudentToStudentAvailibility(team[1], team[2]);
	timeCompareScore += StudentToStudentAvailibility(team[1], team[3]);
	timeCompareScore += StudentToStudentAvailibility(team[1], team[4]);
	timeCompareScore += StudentToStudentAvailibility(team[2], team[3]);
	timeCompareScore += StudentToStudentAvailibility(team[2], team[4]);
	timeCompareScore += StudentToStudentAvailibility(team[3], team[4]);

	    //score 0-40
		return timeCompareScore;

		//configure the score from 0-40 to 0-20
		float percent= 0;
		float max = 40;
		percent = timeCompareScore/ max;
		percent = percent * 20;
		percent = (int)percent;

		//return the score 0-20
		return percent;

}

//helper function for AvailabilityTeamScore, compares 2 students
//returns an Availability comparison score of 0 - 4.
int StudentsToProjects::StudentToStudentAvailibility(Student s1, Student s2){

	int score = 0;

	//checks preferred weekday selections
	if(s1.Availability[0] == s2.Availability[0]){
		score += 2;
	}else if ((s1.Availability[1] == s2.Availability[1]) | (s1.Availability[1] == s2.Availability[0]) |(s1.Availability[0] == s2.Availability[1])){
		score += 1;
	}

	//checks preferred weekend selections
	if(s1.Availability[2] == s2.Availability[2]){
			score += 2;
		}else if ((s1.Availability[3] == s2.Availability[3]) | (s1.Availability[3] == s2.Availability[2]) |(s1.Availability[2] == s2.Availability[3])){
			score += 1;
		}

	return score;
}

// This function returns a score of 0-40 determining
// the quality of the team by comparing the student's skills to each other
int StudentsToProjects::SkillCompareTeamScore(Student team[5]){


int teamCompareScore = 0;

teamCompareScore += StudentToStudentSkill(team[0], team[1]);
teamCompareScore += StudentToStudentSkill(team[0], team[2]);
teamCompareScore += StudentToStudentSkill(team[0], team[3]);
teamCompareScore += StudentToStudentSkill(team[0], team[4]);
teamCompareScore += StudentToStudentSkill(team[1], team[2]);
teamCompareScore += StudentToStudentSkill(team[1], team[3]);
teamCompareScore += StudentToStudentSkill(team[1], team[4]);
teamCompareScore += StudentToStudentSkill(team[2], team[3]);
teamCompareScore += StudentToStudentSkill(team[2], team[4]);
teamCompareScore += StudentToStudentSkill(team[3], team[4]);

	return teamCompareScore;

}

//helper function for SkillCompareTeamScore
//returns a student to student comparison score of 0 - 4.
int StudentsToProjects::StudentToStudentSkill(Student s1, Student s2){

	  int skillsum1 = 0;
	  int skillsum2 = 0;
	  int score = 0;

	  for(int i = 0; i < 7; i++){

		 skillsum1 += s1.Skills[i];
		 skillsum2 += s2.Skills[i];
	  }

	  score = skillsum1 - skillsum2;
	  score = abs(score);

	  if (score == 0 || score == 1){
	  	return 4;

	  	}else if(score == 2 || score == 3){
	  	return 3;

	  	}else if(score == 4 || score == 5){
	  	return 2;

	  	}else if(score > 5 && score < 9){
	  	return 1;

	  	}else if(score >= 9){
	  	return 0;

	  	}

}


// This function returns a score of 0-40 determining
// the quality of the team by comparing the max skills a team could have
// on a certain project, to the team's overall skills.
int StudentsToProjects::ProjectCompareTeamScore(Student team[5], Project project){

	int numSkills = 7;
	int teamSize = 5;
	int maxProjectScore = 0;
	int teamSkillSum = 0;

	//find the maximum score a team could get on this project
	for( int i = 0; i < numSkills ; i++ ){

		maxProjectScore += project.Skills[i] * 4;
	}
	maxProjectScore = maxProjectScore * teamSize;

	//find the sum of the team's skills for this project
	for( int i = 0; i < teamSize ; i++ ){
		for( int j = 0; j < numSkills ; j++ ){
			teamSkillSum += team[i].Skills[j] * project.Skills[j];
	}}

    //calculate percentage
	float percent= 0;
	float max = 0;
	max = maxProjectScore;
	percent = teamSkillSum/ max;
	percent = percent * 40;
	percent = (int)percent;

    //return the score 0-40
	return percent;

}


StudentsToProjects::~StudentsToProjects() {
	// TODO Auto-generated destructor stub
}

