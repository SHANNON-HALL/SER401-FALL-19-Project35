/*
 * ResultWindow.cpp
 *
 * Description:  prints out the team assignment results for the user to review
 *
 *
 * Created on:   01/29/2020
 *
 * Authors:   M. Cilibra, M. Colina, C. DeLeo, E. Marquise, S. Rogers
 *
 * List of functions:
 *
 */

#include "ResultWindow.h"
#include "main.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>


#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_RGB_Image.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input_.H>
#include <FL/Fl_Text_Buffer.H>


using namespace std;


//Function to convert integers into constant expressions.
constexpr int toConstInt(int constInt) {
	return constInt;
}


/* constructor, preps the results window and buffer */
ResultWindow::ResultWindow() {

    // MAIN WINDOW
    windowResult = new Fl_Window(640, 480, "Project 35");

    // Buffer
    buffer = new Fl_Text_Buffer();

    //Text Display
    textDisplay = new Fl_Text_Display(20,90,640-40,480-110, "Results:");
    textDisplay->buffer(buffer);

    //Save BUTTON
    buttonSave = new Fl_Button(20,20,100,50, "Save Report");
    buttonSave->callback(static_saveClicked, this);

    permBox = new Fl_Box(150, 20, 200, 40, "");
    swapBox = new Fl_Box(150, 40, 200, 40, "");

}


/* event handler for the save button. Saves file as .txt */
void ResultWindow::saveClicked(Fl_Widget* w) {
	cout <<"Saving Report as .csv" <<endl;
	buffer->savefile("results.csv", 1000000);
}


/* method to show the results window once the buffer has been filled */
void ResultWindow::addText() {
    windowResult->resizable(textDisplay);

    char permNum[50];
    int buff = sprintf(permNum, "Number of possible permutations: %d", permutations);
    const char* permNum1 = permNum;
    permBox->label(permNum1);

    char swapNum[50];
    buff = sprintf(swapNum, "Number of students swapped: %d", swaps);
    const char* swapNum1 = swapNum;
    swapBox->label(swapNum1);

    windowResult->show();
    windowResult->end();
    Fl::run();
}


// DESTRUCTOR
ResultWindow::~ResultWindow() {
    // TODO
}
