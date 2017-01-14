/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Cipher.h
 * Author: oli
 *
 * Created on 10 December 2016, 18:35
 */

#ifndef CIPHER_H
#define CIPHER_H
#define __STDC_FORMAT_MACROS
#include <iostream>
#include "Buffer.h"
#include <stdio.h>
#include <inttypes.h>
#include <fstream>

/*
 this is for performing mathmatical and logical operations on blocks, like shifts or xors, eventually will be used to encrypt or hash blocks,whihc can then be sotred in images or written to file
 comments explain functions below

 
 
 
 
 
 */
namespace Cipher
{
    //this simply xors one block with another, both must be same size
      void XorBlocks(unsigned char* data,unsigned char * key, int blocksize)
    {
        for(int n = 0; n<blocksize; n++)
        data[n] ^=key[n];
        
    }

    /*this function xors one block with another, the first bit of each byte is xor with the corresponding bit of the first byte in other  block, this is a different way of xoring two blocks
     for example, for visualisation, these are the bytes in buffer1:
     Col  :   12345678
     Byte 1:  10101010
     Byte 2:  10101010
     Byte 3:  10101010
     Byte 4:  10101010
     Byte 5:  10101010
     Byte 6:  10101010
     Byte 7:  10101010
     Byte 8:  10101010
     column one xored with the first byte of buffer2 e.g 11111111^ buffer2[0]
	 
    column two xored with the second byte of buffer2
    and so on
     
     
     
     */
  
    void MatrixXor(unsigned char* data,unsigned char * key)//data is 8 bytes long, key is 8 bytes long
    {
        int N = 0;
        int B = 0;
     
        for(int A= 0, N = 0; A<64; A++, N++)
        {
            //N is 0-7, shifts the bit to get correct bit, also iterates through bytes
            //B is 0-7, is the index of key that is being used for xor
		
            

            data[N] ^= (-(((data[B] >> N) & 1)^((key[B] >> N) & 1)) ^ data[B]) & (1 << N);
   
            if(N==7)
            {
                N = -1;
                B++;
            }
        
        }
     
    
    
    }
    //same as above but only one of the columns(B) is xored with key(single byte)
    void OneByteMatrixXor(unsigned char* data,unsigned char  key, int B)
    {
      
   

        for(int N = 0; N<8; N++)
        {
            
           // std::cout<<N<<" "<<B<<std::endl;
            data[N] ^= (-(((data[N] >> B) & 1)^((key >> B) & 1)) ^ data[N]) & (1 << B);
        
   
          
        
        }
     
    
    
    }
    void R3(unsigned char* data, unsigned char n, bool mode)// data is 8 bytes long, therefore n must be 1 byte, n must be below 65, 
    {
        //this is for a bitewise rotate carry shift, the data is copyed into a 64 bit buffer, shifted and then copyed back to original buffer
        
        uint64_t A;// only available on 64bit machines
        memcpy(&A, data, 8);
     
        
      
        if(mode)
        {
        A = A  << n | A>> (64 - n);// forward shift
       
        }
        else
        {
        A = A >> n | A<<(64-n);// reverse shift
        }
        std::memmove(data, &A, 8);
      
      

        
     
       
       
       
        
        
        
        
        
        
    }
  
    
    
    
    
    
    
};




#endif /* CIPHER_H */
