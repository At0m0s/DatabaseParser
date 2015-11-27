/*
 * parser.cc
 *
 *  Created on: Nov 21, 2015
 *      Author: At0m0s
 */
 
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <sstream>

using namespace std;
using namespace boost;

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <delimeter> <input file> <output file> <userIndex> <passIndex>" << endl;
        return 1;
    }

    istringstream us(argv[5]);
    istringstream ps(argv[6]);
    int userIndex;
    int passIndex;
    if (!(us >> userIndex))
        cerr << "Invalid number " << argv[5] << endl;
    if(!(ps >> passIndex))
        cerr << "Invalid number " << argv[6] << endl;
    
    cout << "Welcome to the combo parser, created by At0m0s." << endl;
    vector <string> fields;
    string line;
    string delimeter = argv[1];
    ifstream inFile (argv[2]);
    ofstream outFile (argv[3]);
    if (inFile.is_open())
    {
        cout << "Parsing file";
        while ( getline (inFile,line) )
        {
            size_t n = std::count(line.begin(), line.end(), '_');
            if (line.find(delimeter) != std::string::npos) {
                if (line.find(";") != std::string::npos || line.find("#") != std::string::npos || line.find("&#") != std::string::npos) {
                    //break;
                }
                else {
                    //cout << line << endl;
                    split( fields, line, is_any_of( delimeter ) );
                    cout << ".";
                    outFile << fields[userIndex] << ":" << fields[passIndex] << endl;
                }
            }
        }
        inFile.close();
        outFile.close();
        cout << "Done!" << endl;
        return 0;
    }
    cout << "Error, could not open file!" << endl;
    return 1;
}


