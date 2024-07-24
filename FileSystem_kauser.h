/*
Author: Jameela Kauser
Date: 2/11/2024
Description: declaration of File and File Manager classes
*/
#ifndef FILESYSTEM_KAUSER_H
#define FILESYSTEM_KAUSER_H
#include <stdio.h>
#include <string>
#include <vector>
#include "LinkedList_kauser.hpp"
#include "Queue_kauser.hpp"

using namespace std;

template<typename T>
class Node;

template<typename T>
class LinkedList;

class File 
{
    private:
    string fileName;
    LinkedList<int> indexBlock; 

public:
    File();
    File(string name);
    string getFileName();
    void addBlock(int index);
    int fileSize();
    LinkedList<int> getFileBlocks();
};

class FileManager
 {
    private:
        char* hardDrive;
        Queue<int> blocksAvailable; 
        LinkedList<File> files; 

    public:
        FileManager(int size);
        ~FileManager();
        void addFile(string& name, string& contents);
        void deleteFile(string& name);
        string readFile(string& name);
        vector<string> getFileNames();
        File* findFileByName(string& name);
};
#endif 