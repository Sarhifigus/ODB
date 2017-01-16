/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StenographyEngine.h
 * Author: oli
 *
 * Created on 15 January 2017, 19:58
 */

#ifndef STENOGRAPHYENGINE_H
#define STENOGRAPHYENGINE_H
#include "Buffer.h"
#include "BlockOperations.h"
#include "StenographyEngine.h"
#include "BitmapOperations.h"


//for inserting data into 24bit bitmap files
///REMEMBER EVERY BYTE IS EMBEDDED IN 8 IMAGE BYTES
namespace Sten// as in stenography(storing data in images)
{
    //string returns an error log
    void insertData(Bitmap *b, unsigned char*data,unsigned int length)//length of data to insert
    {
        
        if(       ((b->imageSize()*3)/8)<length)//the amount of image data must be 8 times the amount of data to embed
        {
            
        }
        else
        {
       
        //first four bytes store how much data has been added, this is like a kind of padding
        
        int index = b->getPixelDataIndex();//point at which we can start embedding data
        unsigned char* padd = new unsigned char[4];
        //Buffer::fillBuffer(padd, 0, 4);
        Buffer::getData(padd,&length,0,4);
     
        
        //index is start of pixel data
       BlockOperator::storeDataInPixels(b->pixels,index, padd, 4);//simply store how much data will be inserted, this takes up 4x8(32) bytes of actual image data
        
       
                                        ///4bytes inserted in 32 bytes, so offset is 32
        BlockOperator::storeDataInPixels(b->pixels,index+32, data, length);
    
        
        }
        
    }
    int retrieveAmountOfData(Bitmap *b)
    {
        //retrieves first four bytes afetr start of image data
        
         int index = b->getPixelDataIndex();//point at which we can start embedding data
        uint32_t amount;  
        unsigned char* am = new unsigned char[4];
        Buffer::fillBuffer(am, 0, 4);
        BlockOperator::getDataInPixels(b->pixels,index, am, 4);
        Buffer::getData(&amount, am, 0,4);
        delete[] am;
        
        return amount;
        
    }
    void retrieveData(Bitmap *b, unsigned char*data, int length)
    {
        int index = b->getPixelDataIndex();//point at which we can start embedding data
     
        
  
        BlockOperator::getDataInPixels(b->pixels,index+32, data, length);
    }
    
    
    
    
    
    
    
    
}


#endif /* STENOGRAPHYENGINE_H */

