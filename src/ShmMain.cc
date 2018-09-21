/*************************************************************************
*
*              Author: b51
*                Mail: b51live@gmail.com
*            FileName: ShmMain.cc
*
*          Created On: Fri 21 Sep 2018 06:01:11 PM CST
*     Licensed under The MIT License [see LICENSE for details]
*
************************************************************************/

#include "shm_util.h"

#include <ros/ros.h>
#include <glog/logging.h>

int main(int argc, char* argv[])
{
  google::InitGoogleLogging(argv[0]);
  google::ParseCommandLineFlags(&argc, &argv, true);

  FLAGS_minloglevel = google::INFO;
  FLAGS_logtostderr = true;
  FLAGS_colorlogtostderr = true;

  int ret = 0;

  /* Init world shm */
  ret = world_shm_create();
  if (ret < 0)
    LOG(ERROR) << "Could not create world shm";
  else
    LOG(INFO) << "World shm created";

  for (auto const& world_key : world_keys)
  {
    LOG(INFO) << "Setting up world key: "
        << world_key.first << "[" << world_key.second.size << "]";
    int nval = world_key.second.size;

    double* pr = world_shm_set_ptr(world_key.first, nval);
    for (int i = 0; i < nval; i++)
    {
      *(pr + i) = 0.;   // Init all shm data to 0.
    }
  }

/* Init vision shm */
  ret = vision_shm_create();
  if (ret < 0)
    LOG(ERROR) << "Could not create vision shm";
  else
    LOG(INFO) << "Vision shm created";

  for (auto const& vision_key : vision_keys)
  {
    LOG(INFO) << "Setting up vision key: "
        << vision_key.first << "[" << vision_key.second.size << "]";
    int nval = vision_key.second.size;

    double* pr = vision_shm_set_ptr(vision_key.first, nval);
    for (int i = 0; i < nval; i++)
    {
      *(pr + i) = 0.;   // Init all shm data to 0.
    }
  }
}
