//****************************************************************************//
// platform.cpp                                                               //
// Copyright (C) 2001, 2002 Bruno 'Beosil' Heidelberger                       //
//****************************************************************************//
// This library is free software; you can redistribute it and/or modify it    //
// under the terms of the GNU Lesser General Public License as published by   //
// the Free Software Foundation; either version 2.1 of the License, or (at    //
// your option) any later version.                                            //
//****************************************************************************//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//****************************************************************************//
// Includes                                                                   //
//****************************************************************************//

#include "cal3d/platform.h"

 /*****************************************************************************/
/** Constructs the platform instance.
  *
  * This function is the default constructor of the platform instance.
  *****************************************************************************/

CalPlatform::CalPlatform()
{
}

 /*****************************************************************************/
/** Destructs the platform instance.
  *
  * This function is the destructor of the platform instance.
  *****************************************************************************/

CalPlatform::~CalPlatform()
{
}

 /*****************************************************************************/
/** Reads a number of bytes.
  *
  * This function reads a given number of bytes from a file stream.
  *
  * @param file The file stream to read the bytes from.
  * @param pBuffer A pointer to the buffer where the bytes are stored into.
  * @param length The number of bytes that should be read.
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happend
  *****************************************************************************/

bool CalPlatform::readBytes(std::istream& file, void *pBuffer, int length)
{
  file.read((char *)pBuffer, length);
  return !file ? false : true;
}

 /*****************************************************************************/
/** Reads a float.
  *
  * This function reads a float from a file stream.
  *
  * @param file The file stream to read the float from.
  * @param value A reference to the float into which the data is read.
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happend
  *****************************************************************************/

bool CalPlatform::readFloat(std::istream& file, float& value)
{
  file.read((char *)&value, 4);

#ifdef CAL3D_BIG_ENDIAN
  float x = value ;
  ((char*)&value)[0] = ((char*)&x)[3] ;
  ((char*)&value)[1] = ((char*)&x)[2] ;
  ((char*)&value)[2] = ((char*)&x)[1] ;
  ((char*)&value)[3] = ((char*)&x)[0] ;  
#endif

  return !file ? false : true;
}

 /*****************************************************************************/
/** Reads an integer.
  *
  * This function reads an integer from a file stream.
  *
  * @param file The file stream to read the integer from.
  * @param value A reference to the integer into which the data is read.
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happend
  *****************************************************************************/

bool CalPlatform::readInteger(std::istream& file, int& value)
{
  file.read((char *)&value, 4);

#ifdef CAL3D_BIG_ENDIAN
  int x = value ;
  ((char*)&value)[0] = ((char*)&x)[3] ;
  ((char*)&value)[1] = ((char*)&x)[2] ;
  ((char*)&value)[2] = ((char*)&x)[1] ;
  ((char*)&value)[3] = ((char*)&x)[0] ;
#endif

  return !file ? false : true;
}

 /*****************************************************************************/
/** Reads a string.
  *
  * This function reads a string from a file stream.
  *
  * @param file The file stream to read the string from.
  * @param value A reference to the string into which the data is read.
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happend
  *****************************************************************************/

bool CalPlatform::readString(std::istream& file, std::string& strValue)
{
  // get the string length
  int length;
  file.read((char *)&length, 4);

#ifdef CAL3D_BIG_ENDIAN
  int x = length ;
  ((char*)&length)[0] = ((char*)&x)[3] ;
  ((char*)&length)[1] = ((char*)&x)[2] ;
  ((char*)&length)[2] = ((char*)&x)[1] ;
  ((char*)&length)[3] = ((char*)&x)[0] ;
#endif

  if(length < 0) return false;

  // read the string
  char *strBuffer;
  strBuffer = new char[length];
  file.read(strBuffer, length);
  strValue = strBuffer;
  delete [] strBuffer;

  return true;
}


 /*****************************************************************************/
/** Writes a number of bytes.
  *
  * This function writes a given number of bytes to a file stream.
  *
  * @param file The file stream to write the bytes to.
  * @param pBuffer A pointer to the byte buffer that should be written.
  * @param length The number of bytes that should be written.
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happend
  *****************************************************************************/

bool CalPlatform::writeBytes(std::ofstream& file, const void *pBuffer, int length)
{
  file.write((char *)pBuffer, length);
  return !file ? false : true;
}

 /*****************************************************************************/
/** Writes a float.
  *
  * This function writes a float to a file stream.
  *
  * @param file The file stream to write the float to.
  * @param value The float that should be written..
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happend
  *****************************************************************************/

bool CalPlatform::writeFloat(std::ofstream& file, float value)
{

#ifdef CAL3D_BIG_ENDIAN
  float x = value ;
  ((char*)&value)[0] = ((char*)&x)[3] ;
  ((char*)&value)[1] = ((char*)&x)[2] ;
  ((char*)&value)[2] = ((char*)&x)[1] ;
  ((char*)&value)[3] = ((char*)&x)[0] ;  
#endif

  file.write((char *)&value, 4);
  return !file ? false : true;
}

 /*****************************************************************************/
/** Writes an integer.
  *
  * This function writes an integer to a file stream.
  *
  * @param file The file stream to write the integer to.
  * @param value The integer that should be written.
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happend
  *****************************************************************************/

bool CalPlatform::writeInteger(std::ofstream& file, int value)
{

#ifdef CAL3D_BIG_ENDIAN
  int x = value ;
  ((char*)&value)[0] = ((char*)&x)[3] ;
  ((char*)&value)[1] = ((char*)&x)[2] ;
  ((char*)&value)[2] = ((char*)&x)[1] ;
  ((char*)&value)[3] = ((char*)&x)[0] ;
#endif

  file.write((char *)&value, 4);
  return !file ? false : true;
}

 /*****************************************************************************/
/** Writes a string.
  *
  * This function writes a string to a file stream.
  *
  * @param file The file stream to write the string to.
  * @param value A reference to the string that should be written.
  *
  * @return One of the following values:
  *         \li \b true if successful
  *         \li \b false if an error happend
  *****************************************************************************/

bool CalPlatform::writeString(std::ofstream& file, const std::string& strValue)
{
  // get the string length
  int length;
  length = strValue.size() + 1;

#ifdef CAL3D_BIG_ENDIAN
  int x = length ;
  ((char*)&length)[0] = ((char*)&x)[3] ;
  ((char*)&length)[1] = ((char*)&x)[2] ;
  ((char*)&length)[2] = ((char*)&x)[1] ;
  ((char*)&length)[3] = ((char*)&x)[0] ;
#endif

  file.write((char *)&length, 4);
  file.write(strValue.c_str(), strValue.size()+1);

  return !file ? false : true;
}

//****************************************************************************//
