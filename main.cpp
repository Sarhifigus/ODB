/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: oli
 *
 * Created on 03 December 2016, 11:26
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>
#include "Buffer.h"
#include "Padding.h"
#include "Filer.h"
#include "CipherLinker.h"
#include "Cipher.h"
#include "BlockOperations.h"


using namespace std;


/*
 *
 */
int main(int argc, char** argv)
{
	//exmaple of storing some data in an image
	//unsigned char* pixel = new unsigned char[64];
   // unsigned char* data = new unsigned char[8];
   // Buffer::fillBuffer(pixel, 254, 64);
   // Buffer::fillBuffer(data, 255, 8);
   // BlockOperator::storeDataInPixels(pixel, data, 8);
   // cout<<(int)pixel[0];// this prints 255
    
    
    
    
  
    //delete[] pixel, data;
    
    
    


  
/*
   // example of reading file, padding then writing back
   // this can be used from reading bmp files, adding data to them and then writing them back
    char mode = 'e';
    //example of use
    switch(mode)
    {
        case 'e':
        {
            string filename = string("ManyDocument.txt");
            const char* file = filename.c_str();
       
            
            int size = Filer::seekLength(file)+Pad::getPadSize(Filer::seekLength(file));
            int len = Filer::seekLength(file);
            int padsize = Pad::getPadSize(len);
            cout<<len<<endl;
            cout<<padsize<<endl;
    unsigned char* buf = new unsigned char[size];
   Filer::readFile(file, buf);// file in file details and then pad and write and then read and unpad  

 
    Pad::padBuffer(buf,padsize, len);


    Filer::writeFile("Document.txt", buf,size);
  
    delete[] buf;
	 break;
        }
   
    
    
        case 'd':
        {
            string filename = string("Document.txt");
            const char* file = filename.c_str();
            int size = Filer::seekLength(file);
            unsigned char *buf = new unsigned char[size];
            Filer::readFile(file, buf);

            int pre = Pad::getPrePadSize(buf, size);

            unsigned char *tex = new unsigned char[pre];
            Buffer::putData(tex,0,buf,pre);
            Filer::writeFile(file, tex, pre);
			 break;
        }
          

    
    }
    
      */
    
    
    


    return 0;
}
