/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BitmapOperations.h
 * Author: oli
 *
 * Created on 15 January 2017, 18:54
 */

#ifndef BITMAPOPERATIONS_H
#define BITMAPOPERATIONS_H
#include "Buffer.h"
#include "Filer.h"
#include <iostream>

// for reference    http://www.dragonwins.com/domains/getteched/bmp/bmpfileformat.htm
class Bitmap
{
public:
    unsigned char* pixels;
    const char* filename;
    Bitmap(const char* file)
    {
        this->filename = file;
        int size = Filer::seekLength(file);
        unsigned char* buf = new unsigned char[size];
        Filer::readFile(file, buf);
        if((buf[0]=='B') && (buf[1]=='M'))// first two bytes of bitmap should be BM
        {
            this->pixels = buf;
           
        }
        else
        {
           
           //wrong format
            
        }
    }
    ~Bitmap()
    {
       delete[] pixels; 
    }
    int fileSize()
    {
        uint32_t A;  
        Buffer::getData(&A, pixels, 2, 4);// bytes 3,4,5,6 show file size
        return A; 
    }
    int getPixelDataIndex()
    {
        uint32_t A;  
        Buffer::getData(&A, pixels, 10, 4); // bytes 10,11,12,13 show when pixel bytes begin
        return A; 
    }
    int imageSize()
    {
        uint32_t A;  
        Buffer::getData(&A, pixels, 18, 4);// bytes 18-22 show width
        uint32_t B;   
        Buffer::getData(&B, pixels, 22, 4); // bytes 22-24 show height
        return A*B; 
    }
    void rewrite()
    {
        Filer::writeFile(filename, pixels, this->fileSize());       
    }
    //this needs to be built upon for when a bitmap is created from data
    
private:
};

#endif /* BITMAPOPERATIONS_H */
