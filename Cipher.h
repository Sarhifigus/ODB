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

//why don't any of these functions have names? what the hell do they do? what's the different between them? where are the comments?

namespace R1
{
	void R1(unsigned char* data, unsigned char* key)//data is 8 bytes long, key is 8 bytes long
	{
		int N = 0; //What are these varibles
		int B = 0;
		//loop will be 64 long think about it, bit by bit
		for(int A = 0, N = 0; A<64; A++, N++) //What are these varibles
		{
			// std::cout<<N<<" "<<B<<std::endl;
			data[N] ^= (-(((data[B] >> N) & 1)^((key[B] >> N) & 1)) ^ data[B]) & (1 << N); //Explain what this does?
			if(N==7)
			{
				N = -1;
				B++;
			}
		}
	}

	void AR1(unsigned char* data, unsigned char key, int B)//data is 8 bytes long, b is 0 to 7 num
	{
		//loop will be 64 long think about it, bit by bit
		for(int N = 0; N<8; N++) // what is n?
		{
			// std::cout<<N<<" "<<B<<std::endl;
			data[N] ^= (-(((data[N] >> B) & 1)^((key >> B) & 1)) ^ data[N]) & (1 << B);// B and N mixed to shite. what the hell does this do?
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

	void R3(unsigned char* data) //what does this do?
	{
		unsigned char* dat[8];
		dat[0] = dat[0] & (data[0]>>7)
		(data[0] >>7)&1
	}
};

#endif /* CIPHER_H */
