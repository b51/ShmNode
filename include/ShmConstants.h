/*************************************************************************
*
*              Author: b51
*                Mail: b51live@gmail.com
*            FileName: ShmConstants.h
*
*          Created On: Fri 14 Sep 2018 08:31:56 PM CST
*     Licensed under The MIT License [see LICENSE for details]
*
************************************************************************/

#ifndef SHM_CONSTANTS_H_
#define SHM_CONSTANTS_H_

#include <map>
#include <utility>

static const char worldShmName[] = "wcm";

static const char* Position[] =
{
  "Position/X/Value",
  "Position/Y/Value",
  "Position/Angle/Value"
};

/*
static struct structWorldKeys
{
  const char* key;
  unsigned int size;
  const char **names;
} world_keys[] = 
{
  {"time", 1, nullptr},
  {"position", sizeof(Position)/sizeof(char*), Position},
  {nullptr, 0, nullptr}
};
*/

struct structWorldKey
{
  unsigned int size;
  const char** names;
};

typedef std::map<const char*, structWorldKey> mapWorldKeys;

static mapWorldKeys world_keys =
{
  {"time", {1, nullptr}},
  {"position", {sizeof(Position)/sizeof(char*), Position}},
};

#endif
