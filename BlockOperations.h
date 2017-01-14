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

namespace BlockOperator
{
    //p is 8 bytes, bytes is 1 byte
     void storeByteInPixel(unsigned char* p, unsigned char bytes)//this only works for 24 bit bitamps, only operates on LSB
    {
        for(int n = 0; n<8; n++)
        {
  
            
            p[n] &= ~(1);// unsets the last bit(0)
            /////////this gets the bit
            p[n] |= ((bytes>>n )&1) << 0;//0 shifts as only setting last bit
          
            
     
        }
        
        
    }
    //24 bytes in 3 bytes out
    unsigned char retrieveByteInPixel(unsigned char* p, unsigned char bytes)// p is 24 bytes not null, byte is 3 bytes long and null
    {
        for(int n = 0; n<8; n++)
        {
            //bits do not need to be unset as they are null already
          
            bytes |= ((p[n]>>0)&1) <<n;
          
            
        }
        return bytes;
        
        
    }
    
   


    //8 bytes store 1 byte
    //p must be of length bytes * 8
    void storeDataInPixels(unsigned char* pixels, unsigned char* bytes, int length)//length is of data to store(bytes))
    {
        int blocksize = 8;
        for(int n = 0; n<length; n++)
        {
       
        unsigned char* block = new unsigned char[blocksize];
        Buffer::getData(block,pixels,(n*blocksize), blocksize);
        
        storeByteInPixel(block,bytes[n]);
    
        Buffer::putData(pixels, (n*blocksize), block, blocksize);
        
            
            
        }
        
        
        
        
    }
    void getDataInPixels(unsigned char* pixels, unsigned char* bytes, int length)//length is of data to store(bytes))
    {
        int blocksize = 8;
        for(int n = 0; n<length; n++)
        {
       
        unsigned char* block = new unsigned char[blocksize];
        Buffer::getData(block,pixels,(n*blocksize), blocksize);
        
        bytes[n] = retrieveByteInPixel(block, bytes[n]);
    
        Buffer::putData(pixels, (n*blocksize), block, blocksize);
        
            
            
        }
        
        
        
        
    }
    
    
   
    
    
    
    
    
    
    
    
}


#endif /* BLOCKOPERATIONS_H */

