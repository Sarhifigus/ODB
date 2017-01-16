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
#include "BitmapOperations.h"
#include "StenographyEngine.h"


using namespace std;


/*
 *
 */
int main(int argc, char** argv)
{
	

    
//unsigned char* pixel = new unsigned char[64];//this is for the image data
//unsigned char* data    = new unsigned char[8];// data to hide in image
//Buffer::fillBuffer(pixel, 254, 64); //this is filled(normally filled from image file)
//Buffer::fillBuffer(data, 12, 8);//data to hide in image, in this case 8 bytes of value 12
//BlockOperator::storeDataInPixels(pixel, data, 8);// the data is inserted
//cout<<(int)pixel[0]<<endl;// 254 remains the same, for other numbers there wil only ever be a +1 or -1 change
//unsigned char* data2 = new unsigned char[8];//the data will be read back here
//Buffer::fillBuffer(data2, 0, 8);//makes sure all values are null
//BlockOperator::getDataInPixels(pixel,data2,8);//retrieves data
//cout<<(int)data2[7];// the output is 12 for every byte in data2
//delete[] data,data2,pixel;
    

  //The following code work but has some problems
    //1    The original text is recovered, however in some cirucmstances random bytes appear on the end
    //2    Multiple other files appear in the same directory with random names on some occasions- memory leak?
    
    /*
    Bitmap *b = new Bitmap("Bitmap.bmp");
    string data = "This is stored in a bitmap";
    int len = data.length();
    unsigned char* buf = (unsigned char*)&data[0];

    Sten::insertData(b, buf, len);
    b->rewrite();
  
    
    delete b;
    
    Bitmap *b2 = new Bitmap("Bitmap.bmp");
    int len2 = Sten::retrieveAmountOfData(b2);
    unsigned char* buf2 = new unsigned char[len2];
    Buffer::fillBuffer(buf2, 0, len2);
    Sten::retrieveData(b2,buf2, len2);
    std::string imagedat(reinterpret_cast<char*>(buf2));
    b->rewrite();


    cout<<imagedat;// prints original text, however with some lengths  additional bytes appear on end, additional debugging and research is required
    */
    //Same as above but a text file is written into the image
    
    
    
    
    
    
    
  
    
    //All data from file is embedded in image
    Bitmap *b = new Bitmap("Bitmap.bmp");
    //b->imageSize(); this should be at least 8 times the size of the file
    
    
    int length = Filer::seekLength("DataToEmbed.txt");
    unsigned char* buffer = new unsigned char[length];
    Filer::readFile("FiftyShadesOfGrey.txt", buffer);

    Sten::insertData(b, buffer, length);
    b->rewrite();
  
    
    delete b;
    
    //retrieves data
    
    Bitmap *b2 = new Bitmap("Bitmap.bmp");
    int len2 = Sten::retrieveAmountOfData(b2);
    unsigned char* buf2 = new unsigned char[len2];
    Buffer::fillBuffer(buf2, 0, len2);
    Sten::retrieveData(b2,buf2, len2);
    
    Filer::writeFile("DataInImage.txt", buf2, len2);//new file contans contents of the original file
    
    //b->rewrite(); //not required as data not changed
    
    
    
    
    
    
    
    
    //unsigned char* buf = new unsigned char[8];
   // Buffer::fillBuffer(buf, 0, 8);
   // int index = b->getPixelDataIndex();
    //BlockOperator::getDataInPixels(b->pixels,index+4, buf, 8);
    //BlockOperator::storeDataInPixels(b->pixels,index, buf,8);
    //cout<<(int)b->pixels[index+63];//amount x 8
   
    
    
  
  


    
    
  
    
    


  
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
