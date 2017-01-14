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

using namespace std;

int main(int argc, char** argv)
{
  unsigned char dat[] = "hello123";
  unsigned char kee[] = "12345678";
  unsigned char* data = &dat[0];
  unsigned char key = 250;
  cout<<(int)data[3]<<endl;
  R1::AR1(data, key, 0);
  cout<<(int)data[3]<<endl;
  R1::AR1(data, key, 0);
  cout<<(int)data[3];

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

      Filer::writeFile("C:/Users/oli/Music/SECURE/ManyDocuments.txt", buf,size);

      delete[] buf;
    }
    break; //Shouldn't these breaks be in the case block???

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
    }
    break;
  }
  return 0;
}
