/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BlockOperations.h
 * Author: oli
 *
 * Created on 13 January 2017, 22:58
 */

#ifndef BLOCKOPERATIONS_H
#define BLOCKOPERATIONS_H
#include <iostream>
/* this is for storing data within an image, for every 24bit pixel 3 bits of actual data is stored
 very little of image is changed, as only least significant bit of each byte is changed to a bity of the data
 for exmaple this could be used to put a story in an image*/
namespace BlockOperator
{
    //p is 8 bytes, bytes is 1 byte
    //p is image data, bytes is the data to insert into image data
     void storeByteInPixel(unsigned char* p, unsigned char bytes)//this only works for 24 bit bitamps, only operates on LSB
    {
        for(int n = 0; n<8; n++)
        {
          //p[n] iterates through each byte, out of 8
          //bytes>>n gets each bit of bytes, starting wiht lowest, this is done but shifting n places so sesired bit is the lowest and then Anded with 1, to give the bits value
            
            p[n] &= ~(1);// unsets the last bit(0)
            /////////this gets the bit
            p[n] |= ((bytes>>n )&1) << 0;//0 shifts as only setting last bit
          
            
     
        }
        
        
    }
    //8 bytes in , 1 byte out
    unsigned char retrieveByteInPixel(unsigned char* p, unsigned char bytes)// p is 8 bytes not null, byte is 1 bytes long and null
    {
        for(int n = 0; n<8; n++)
        {
            //bits do not need to be unset as they are null already
          
            bytes |= ((p[n]>>0)&1) <<n;
          
            
        }
        return bytes;
        
        
    }
    
   


    //8 bytes store 1 byte
    //pixels must be of length bytes * 8
	//pixels is image data, bytes are data to be hidden
    //this uses functions above(storeByteInPixel) to insert many bytes of data into image
    void storeDataInPixels(unsigned char* pixels,int index, unsigned char* bytes, int length)//length is of data to store(bytes))
    {
        int blocksize = 8;
        for(int n = 0; n<length; n++)
        {
       
        unsigned char* block = new unsigned char[blocksize];// goes throuhg image data 8 bytes at a time and inserts 1 byte of data(bytes)
        Buffer::getData(block,pixels,index+(n*blocksize), blocksize);
  
        
        storeByteInPixel(block,bytes[n]);
    
        Buffer::putData(pixels, index+(n*blocksize), block, blocksize);
        
        delete[] block;
       
        
            
            
        }
        
        
        
        
    }
    //reverse of above function
    void getDataInPixels(unsigned char* pixels,int index, unsigned char* bytes, int length)//length is of data to store(bytes))
    {
        int blocksize = 8;
        for(int n = 0; n<length; n++)
        {
       
        unsigned char* block = new unsigned char[blocksize];
        Buffer::getData(block,pixels,index+(n*blocksize), blocksize);
        
        bytes[n] = retrieveByteInPixel(block, bytes[n]);
    
        Buffer::putData(pixels, index+(n*blocksize), block, blocksize);
        
        delete[] block;
        
            
            
        }
        
        
        
        
    }
    
    
   
    
    
    
    
    
    
    
    
}


   
    
    
    
    
    
    
    
   



#endif /* BLOCKOPERATIONS_H */

