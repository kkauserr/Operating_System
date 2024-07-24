/*
Author: Jameela Kauser
Date: 2/11/2024
Description: cpp file with implementation of FileSystem that was declared in .h file including mathods of File and FileManager
*/
#include <string>
#include "FileSystem_kauser.h"


   File::File()
  {
  }
  File::File(string newName): fileName(newName)
  {
  }
  string File::getFileName()
   {
    return this->fileName;
   }
   void File::addBlock(int index)
   {
    this->indexBlock.addTail(index);
   }
   int File::fileSize()
   {
    return (this->indexBlock).size();    
   }
   LinkedList<int> File :: getFileBlocks()
   {
     return this->indexBlock;
   }



    FileManager::FileManager(int size)
    {
        this->hardDrive=new char[size];
        for (int i=0;i<size;i++)
        {
            (this->blocksAvailable).enqueue(i);
        }
    }; 
    
    FileManager::~FileManager() 
    {
    delete[] this->hardDrive;
    }
    
    void FileManager ::addFile(string& name, string& contents)
    {
        if(blocksAvailable.size()< contents.length())
        {
            throw out_of_range("Not enough space!");
        }
        File* fileNew= new File(name);
        for (char ch : contents) 
        {
        int blockIndex = blocksAvailable.front(); 
        blocksAvailable.dequeue(); 
        hardDrive[blockIndex] = ch;
        fileNew->addBlock(blockIndex); 
        }
        files.addTail(*fileNew);
    }
    
    File* FileManager::findFileByName(string& name)
    {
        Node<File>* currentNode = files.getFront(); 
        while (currentNode!= nullptr) 
        {
            if ((currentNode->getItem()).getFileName() == name) 
            {
                File* getFile=new File(currentNode->getItem());//****
                return  getFile;
            }
            currentNode = currentNode->getNext(); 
        }
        return nullptr; 
}
    
    void FileManager::deleteFile(string& name)
    {
        
        File* delFile = findFileByName(name);
        if (delFile == nullptr) 
        {
          throw out_of_range("File Not Found!");
        }
        LinkedList<int> newBlocks = delFile->getFileBlocks();
        Node<int>* current = newBlocks.getFront();
        while (current != nullptr) 
        {
            int blockIndex = current->getItem();
            current = current->getNext();
            blocksAvailable.enqueue(blockIndex);
            hardDrive[blockIndex] = '\0'; 
        }
        files.removeFromList(*delFile);
        delete delFile;
    }
    
    string FileManager :: readFile(string& name)
    {
        File* fileToFind = findFileByName(name);
        if (fileToFind == nullptr) 
        {
            throw out_of_range("File Not Found!");
            return "";
        }
        string fileContent;
        LinkedList<int> blockIndexes = fileToFind->getFileBlocks();
        Node<int>* currentNode = blockIndexes.getFront();
        while (currentNode != nullptr) 
        {
            int blockIndex = currentNode->getItem();
            fileContent += hardDrive[blockIndex]; 
            currentNode = currentNode->getNext();
        }

    return fileContent;
    }
    
    vector<string> FileManager::getFileNames()
    {
        vector<string> names;
        Node<File>* current = files.getFront(); 
        while (current != nullptr) {
            names.push_back((current->getItem()).getFileName()); 
            current=current->getNext();
        }
        return names;
    }

