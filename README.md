# ODB
Low level buffer libary for operating on small blocks of data one block at a time, can be used for image recognition, pixel manipulation/stenography, block ciphers(includes two padding methods) and creating bitmaps from data.





Aims
-To store large text files in images, without making noticable change to image.
-To retrive data from images aswell as knowing how much to retrieve
-To pad and encrypt data and then hide it in image
-To search for patterns within images


Common Errors:
When a buffer is created:
char buf * = new char[128];
the values are not null(even if unsigned), if passed to library then data will be corrupted, and so when a buffer is created pass it to:
Buffer:fillBuffer(buf, 0, 128);
this sets all values to 0

When a buffer is created there is no way to find the length of it, so keep track of it to avoid overflows

Aslo delete buffers when finished with them

Examples of use:

Data in images:

unsigned char* pixeldata = new unsigned char[64];//this is for the image data
unsigned char* data    = new unsigned char[8];// data to hide in image
Buffer::fillBuffer(pixel, 254, 64); //this is filled(normally filled from image file)
Buffer::fillBuffer(data, 12, 8);//data to hide in image, in this case 8 bytes of value 12
BlockOperator::storeDataInPixels(pixel, data, 8);// the data is inserted
cout<<(int)pixel[0]<<endl;// 254 remains the same, for other numbers there wil only ever be a +1 or -1 change
unsigned char* data2 = new unsigned char[8];//the data will be read back here
Buffer::fillBuffer(data2, 0, 8);//makes sure all values are null
BlockOperator::getDataInPixels(pixel,data2,8);//retrieves data
cout<<(int)data2[0];// the output is 12 for every byte in data2
delete[] data,data2,pixeldata;


Padding(PKCS7)

const char* file = filename.c_str();
 int size = Filer::seekLength(file)+Pad::getPadSize(Filer::seekLength(file));//returns the size of the buffer to hold data and padding
 int len = Filer::seekLength(file);// length of the file
int padsize = Pad::getPadSize(len);//returns amount of padding required for data length to be multiple of blocksize
unsigned char* buf = new unsigned char[size];//creates buffer big enough to hold all
Filer::readFile(file, buf);// reads file into buffer
Pad::padBuffer(buf,padsize, len);//adds to padding to end of buffer
Filer::writeFile("Document.txt", buf,size);//writes padded data to document
  
delete[] buf;




