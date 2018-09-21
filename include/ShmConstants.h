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

static const char visionShmName[] = "vcm";
static const char worldShmName[] = "wcm";
static const char gctrlShmName[] = "gcm";

static const char* BoundingBox[] =
{
  "BoundingBox/X/Value",
  "BoundingBox/Y/Value",
  "BoundingBox/Width/Value",
  "BoundingBox/Height/Value",
};

static const char* Pose[] =
{
  "Pose/X/Value",
  "Pose/Y/Value",
  "Pose/Angle/Value"
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
  {"position", sizeof(Pose)/sizeof(char*), Pose},
  {nullptr, 0, nullptr}
};
*/

struct structKeyValue
{
  unsigned int size;
  const char** names;
};

typedef std::map<const char*, structKeyValue> mapKeyValue;

static const char ball_bbox_key[] = "ballBoundingBox";
static const char goal_bbox_key[] = "goalBoundingBox";

static mapKeyValue vision_keys =
{
  {ball_bbox_key, {sizeof(BoundingBox)/sizeof(char*), BoundingBox}},
  {goal_bbox_key, {sizeof(BoundingBox)/sizeof(char*), BoundingBox}},
};

static const char pose_key[] = "pose";

static mapKeyValue world_keys =
{
  {"time", {1, nullptr}},
  {pose_key, {sizeof(Pose)/sizeof(char*), Pose}},
};

#endif
