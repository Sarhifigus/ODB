/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Padding.h
 * Author: oli
 *
 * Created on 03 December 2016, 15:20
 */

#ifndef PADDING_H
#define PADDING_H
#include "Buffer.h"

namespace Pad
{
	//array of unsigned chars, std::vector is ok
	//
	int blocksize = 8;

	int getPadSize(int len)
	{
		int p;

		if(len<blocksize)
		{
		 p = blocksize-len;
		}
		else if(len%blocksize==0)// padding is always added
		{
			p = blocksize;
		}
		else
		{
			p = blocksize-(len%blocksize);
		}
		return p;
	}

	long getPadSize(long len)
	{
		long p;

		if(len<blocksize)
		{
			p = blocksize-len;
		}
		else if(len%blocksize==0)
		{
			p = blocksize;
		}
		else
		{
			p = blocksize-(len%blocksize);
		}
		return p;
	}

	void padBuffer(unsigned char *data, int padsize, int length)// each padded byte has value of amount of padding required, known as PKCS7, cryptosecure depending on blocksize
	{
		unsigned char c = padsize;
		Buffer::insertByte(data,c,length,padsize );
	}

	int getPrePadSize(unsigned char *data, int length)
	{
		int padsize = data[length-1];
		return length-padsize;
	}

	unsigned char* removePadding(unsigned char *data, int length)
	{
		int padsize = data[length-1];

		unsigned char* rem = new unsigned char[length-padsize];
		Buffer::putData(rem,0,data,length-padsize);
		return rem;
	}

	void padBuffer(unsigned char *data, unsigned char *padding, int padsize, int length)// padding is added from other buffer, secure for any blocklength
	{
		unsigned char c = padsize;
		//Buffer::putData(ch
		//char* des, int index, char* loc, int amount)
		Buffer::putData(data,length, padding,padsize-1);
		length = length+padsize;
		Buffer::insertByte(data, c,length, 1);
	}
};

#endif /* PADDING_H */
