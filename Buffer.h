/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Buffer.h
 * Author: oli
 *
 * Created on 03 December 2016, 13:06
 */

#ifndef BUFFER_H
#define BUFFER_H
namespace Buffer
{
	void getData(void *des, void *loc, int index, int amount)
	// the small char aray, loc is large one, index is point to take data from large, int is amount(block size)
	{
		memcpy(des, loc + index, amount);
	}
	void putData(void *des, int index, void *loc, int amount)
	//des is large array. index is index of large array, oc is smaller array, int amout lis size opf small array(block size))
	{
		memcpy(des + index, loc, amount);
	}
	void insertByte(unsigned char *des, unsigned char input, int index, int amount)//this is not working
	{
		memset(des + index, input, amount);
	}
	void fillBuffer(unsigned char *des, unsigned char input, int amount)//used to fill buffer, should be done to set all byte sin buffer to null
	{
		memset(des, input, amount);
	}
	void moveBuffer(void* des, int index, const void * source, int index2, int amount)
	{
	 //memmove(des+index, source+index2, amount);
	}
};

#endif /* BUFFER_H */
