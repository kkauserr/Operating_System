/*
Author: Jameela Kauser
Date: 2/11/2024
Description: Hello programmer, stupid.os needs a new file system built. We need to complete a
prototype demonstrating how we can link together file chunks to store files on
the hard drive. The makers of stupid.os remind us that they don’t have any time
or care for little things like directories, nope it’s just one big folder for
their users! This is a templated queue. This is main.cpp with menu options, prompts user eith these options and performs the required action through switch case
*/
#include "FileSystem_kauser.h"
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <sstream>
#include <limits>
//using namespace std;

int main(int argc, char* argv[]) 
{
    int size = 0;
    string filename;
    for (int i = 1; i < argc; i++) 
    {
        if (string(argv[i]) == "-s" && i + 1 < argc) 
        {
            size = stoi(argv[++i]); 
        } else if (string(argv[i]) == "-f" && i + 1 < argc) 
        {
            filename = argv[++i]; 
        }
    }
    FileManager fileManager(size); 
    if (!filename.empty()) 
    {
        //ifstream file(filename);
        fstream readFile;
        readFile.open(filename,ios:: in);
        if(readFile.is_open())
        {
            string line;
            while (getline(readFile, line)) 
        {
            istringstream iss(line);
            string name, content;
            if (getline(iss, name, ':') && getline(iss, content)) 
            {
                fileManager.addFile(name, content);
            }
        }
        readFile.close();
        }
        
    }
    int choice=-1;
    
    do {
        cout << "Menu:\n"
                  << "1 - Show files on hard drive\n"
                  << "2 - Add a file\n"
                  << "3 - Delete a file\n"
                  << "4 - Output a file\n"
                  << "0 - Exit simulation\n";
                  //<< "Enter option: ";
        cin >> choice;
        switch (choice) 
        {
            case 1: 
            {
                auto fileNames = fileManager.getFileNames();
                cout << left << setw(40) << "Filename" << right << setw(14) << "size" << endl;
                for (auto& name : fileNames) 
                {
                    File* file = fileManager.findFileByName(name);
                    if (file != nullptr) 
                    {
                        cout << left << setw(40) << name 
                                  << right << setw(10) << file->fileSize() << " blk" << endl;
                    }
                }
                break;
                 }
            case 2: 
            {
                string fileName, content;
                cin.ignore(); 
                cout << "Enter filename: ";
                //getline(cin, fileName);
                cin >> fileName;
                cout << "Enter content string: ";
                //getline(cin, content);
                cin >> content;
                fileManager.addFile(fileName, content);
                break;
            }
             case 3: 
             {
                string fileName;
                cin.ignore();
                cout << "Enter filename: ";
                //getline(std::cin, fileName);
                cin >> fileName;
                fileManager.deleteFile(fileName);
                break;
            }
             case 4: 
             {
                string fileName;
                cin.ignore();
                cout << "Enter filename: ";
                //getline(cin, fileName);
                cin >> fileName;
                string content = fileManager.readFile(fileName);
                cout << left << setw(30) << "Filename" 
                          <<right << "Contents" <<endl;
                cout << left << setw(30) << fileName 
                          <<right << setw(30) << content <<endl;
                break;
            }
        }
        } 
         while (choice != 0);
        exit(1);
    return 0;
}