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

static const char* Detection[] =
{
  "Detected",

  "Position/X/Value",
  "Position/Y/Value",
  "Position/Z/Value",

  "BoundingBox/X/Value",
  "BoundingBox/Y/Value",
  "BoundingBox/Width/Value",
  "BoundingBox/Height/Value",
};

static const char* Pose2d[] =
{
  "Pose/X/Value",
  "Pose/Y/Value",
  "Pose/Angle/Value"
};

static const char* TimedPosition3d[] =
{
  "Time/Value",

  "Position/X/Value",
  "Position/Y/Value",
  "Position/Z/Value"
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

///////////////////////////////////////////////////////////////////////
typedef std::map<const char*, structKeyValue> mapKeyValue;

static const char ball_detection_key[] = "ballDetection";
static const char goal_detection_key[] = "goalDetection";
static const char spot_detection_key[] = "spotDetection";

static mapKeyValue vision_keys =
{
  {"timestamp", {1, nullptr}},
  {ball_detection_key, {sizeof(Detection)/sizeof(char*), Detection}},
  {goal_detection_key, {sizeof(Detection)/sizeof(char*), Detection}},
  {spot_detection_key, {sizeof(Detection)/sizeof(char*), Detection}},
};

///////////////////////////////////////////////////////////////////////
static const char pose_key[] = "pose";
static const char ball_global_key[] = "ballGlobal";
static const char goal_global_key[] = "goalGlobal";

static mapKeyValue world_keys =
{
  {"timestamp", {1, nullptr}},
  {pose_key, {sizeof(Pose2d)/sizeof(char*), Pose2d}},
  {ball_global_key, {sizeof(TimedPosition3d)/sizeof(char*), TimedPosition3d}},
  {goal_global_key, {sizeof(TimedPosition3d)/sizeof(char*), TimedPosition3d}},
};

#endif
