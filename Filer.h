/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Filer.h
 * Author: oli
 *
 * Created on 06 December 2016, 19:37
 */

#ifndef FILER_H
#define FILER_H

#include <fstream>
#include "Padding.h"
namespace Filer
{
    long seekLength(const char* dir)
    {
       std::ifstream file(dir,std::ifstream::binary);
       file.seekg(0, file.end);
       long size = file.tellg();
       file.close();
       file.seekg (0);
       return size;
        
        
    }
    void readFile(const char * dir,unsigned  char* buffer)
    {
         std::ifstream file(dir,std::ifstream::binary);
       file.seekg(0, file.end);
       long size = file.tellg();
       
       file.seekg (0);



        file.read ((char*)buffer,size);
       
        file.close();
  
     
    }
    void writeFile(const char* dir, unsigned char* data, int length)
    {
        
        std::ofstream file(dir, std::ofstream::binary);

  
        file.write ((char*)data,length);
        
        
        
    }
    
    
    
    
    
    
};


#endif /* FILER_H */

