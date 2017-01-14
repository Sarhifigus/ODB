/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   CipherLinker.h
 * Author: oli
 *
 * Created on 08 December 2016, 18:44
 */

#ifndef CIPHERLINKER_H
#define CIPHERLINKER_H
#include "Buffer.h"
#include "Cipher.h"
#include <iostream>
namespace CipherLinker// daat is pre padded, leaves with padding, must go throug removePadding, this does not asccount for CBC mode
{
	 int blocksize  = 8;
    
     
    
    void OperateOnBlock(unsigned char* data,unsigned char* key,  int length)
    {
       
        for(int n = 0; n<(length/blocksize); n++)
        {
      
        unsigned char* block = new unsigned char[blocksize];
        Buffer::getData(block,data,(n*blocksize), blocksize);
        //operation goes here, from cipher or BlockOperators

       
        Buffer::putData(data, (n*blocksize), block, blocksize);
        delete[] block;

        }
        
        
        
        
    }
    
    void ReverseOperateOnBlock(unsigned char* data, int length)
    {
        for(int n = 0; n<(length/blocksize); n++)
        {
        unsigned char* block = new unsigned char[blocksize];
        Buffer::getData(block,data,(n*blocksize), blocksize);
       // reverse of operation, mainly for cipher
  
        Buffer::putData(data, (n*blocksize), block, blocksize);
        }
    }
    
    
}


#endif /* CIPHERLINKER_H */
