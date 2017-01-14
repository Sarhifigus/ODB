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

namespace R1
{

    void xorBlocks(unsigned char* b1, unsigned char* b2, int blocklength)// b2 is bascially iv
    {
        for(int n = 0; n<blocklength; n++)
            {
        b1[n] = b1[n]^b2[n];
            }

    }
    
    void R1(unsigned char* data,unsigned char * key)//data is 8 bytes long, key is 8 bytes long
    {
        int N = 0;
        int B = 0;
     //loop will be 64 long think about it, bit by bit
        for(int A= 0, N = 0; A<64; A++, N++)
        {
            
           // std::cout<<N<<" "<<B<<std::endl;
            data[N] ^= (-(((data[B] >> N) & 1)^((key[B] >> N) & 1)) ^ data[B]) & (1 << N);
   
            if(N==7)
            {
                N = -1;
                B++;
            }
        
        }
     
    
    
    }
    void AR1(unsigned char* data,unsigned char  key, int B)//data is 8 bytes long, b is 0 to 7 num, 
    {
      
   
     //loop will be 64 long think about it, bit by bit
        for(int N = 0; N<8; N++)
        {
            
           // std::cout<<N<<" "<<B<<std::endl;
            data[N] ^= (-(((data[N] >> B) & 1)^((key >> B) & 1)) ^ data[N]) & (1 << B);// B and N mixed to shite
        
   
          
        
        }
     
    
    
    }
    void R3(unsigned char* data, unsigned char n, bool mode)// data is 8 bytes long, therefore n must be 1 byte
    {
        uint64_t A;
        memcpy(&A, data, 8);
     
        
      
        if(mode)
        {
        A = A  << n | A>> (64 - n);
       
        }
        else
        {
        A = A >> n | A<<(64-n);
        }
        std::memmove(data, &A, 8);
      
      

        
     
       
       
       
        
        
        
        
        
        
    }
    void R3(unsigned char* data)
    {
        unsigned char* dat[8];
        dat[0] = dat[0] & (data[0]>>7)
        (data[0] >>7)&1
        
        
    }
    
    
    
    
    
    
    
};




#endif /* CIPHER_H */

