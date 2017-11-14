//============================================================================
// Name        : HW_3_ER.cpp
// Author      : Emma Redfoot
// Version     :
// Copyright   : Your copyright notice
// Description : LCG pseudorandum number generator
//============================================================================

#include <iostream>
#include <math.h>
#include</Users/emmaredfoot/eclipse-workspace/Homework/HW_3_hdr.h>
#include <fstream>
using namespace std;

//Define a counter for each random number generated
long int numCalls = 0;

//Begin main function, which will call and print the random number generated
int main() {
//Ask for the length of the range of random numbers to be generated: 100; 10,000; 1,000,000; 100,000,000
long int range;
cout << "How many random numbers would you like generated (100; 10,000; 1,000,000; 100,000,000)? ";
cin >> range;

//Ask for the multiplier for the random number generator
int g=0;
cout << "What would you like the multiplier for the random number generator to be? [60, 61, 62]" << endl;
cin >> g;

//Define the final variable which the answer will be stored in and printed
double answer=0;

//Define the variable that will add up all of the answer values in order to find the mean
double numerator=0;

//Define the array that will track how often each value occurs



//Make a csv file to import into a python file for a  histogram plot of the answer array
ofstream myfile;
myfile.open("answer_data_60.csv");

//Use a do-while loop to initiate calling the random number generator
do{
    answer = randlcg(range, g);
    //cout << "lcg[" << numCalls << "] = " << answer << endl;
    numerator += answer;

    //Write answer values to a csv in order to make a histogram
    myfile << answer << endl;

    //initialize iterator for the frequency array.  Since the w++ has to be in the for loop
    //and we want to frequency array to start at zero, I am initializing it here at -1
    int w=-1;

    //Find the frequency of each value
    for(float iterator=0; iterator <= 1; iterator += .01){
        w++;
        if((answer > iterator) && (answer <= iterator+.01)){
            frequency[w]+=1;
        }
    }
}while(numCalls<range);

myfile.close();

//Find the average by dividing by the total number of values in the array
double average = 0;
average = numerator/range;
cout << "The mean = " << average << endl;
}

//Build a function to actually generate the random number. Make sure it is a float in order to pass back a normalized (between 0-1) value
double randlcg(int range, int g) {
    long int lcg_array[range];
    double normalize;
    lcg_array[0]= 100001;
    int c = 1;
    long int modulus = pow(2,24);
    long int frequency[100]={0};
    for(int x=1; x<range; x++)
        lcg_array[x] = (lcg_array[x-1]*g + c)%modulus;
    //cout << lcg_array[numCalls] << endl;
    normalize = double(lcg_array[numCalls])/modulus;
    return normalize;
}
