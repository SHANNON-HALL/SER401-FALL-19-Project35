/*
 * Test.h
 *
 *  Copyright (C) 2020 ASU
 *	Matthew Cilibraise, Myles Colina, Cristi DeLeo, Elizabeth Marquise, Sean Rogers,
 *	initial idea contributed by Douglas Sandy, All rights reserved
 */

#ifndef TEST_H_
#define TEST_H_

#include "Project.h"
#include "Student.h"

#include <array>

namespace std {

class Test {
public:
	Test();
	void PrintProjectPool(Project projectPool[], int numProjects,
			int numSkills);
	void PrintStudentPool(Student studentPool[], int numStudents,
			int numSkills);
	void PrintProjectStudentSkills(int projectStudentSkills[], int numProjects,
			int numStudents);
	void PrintPercentMatrix(int percentMatrix[], int numProjects,
			int numClassSections);
	void InitializeProjectStudentSkillMatrixTest(int projectXstudent[],
			int numProjects, int numStudents);
	void StructTest();
	~Test();
};
}
#endif /* BRUTEFORCE_SRC_MAIN_TEST_H_ */
