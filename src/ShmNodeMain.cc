/*************************************************************************
*
*              Author: b51
*                Mail: b51live@gmail.com
*            FileName: ShmNodeMain.cc
*
*          Created On: Thu 13 Sep 2018 06:36:49 PM CST
*     Licensed under The MIT License [see LICENSE for details]
*
************************************************************************/

#include <iostream>
#include <string.h>
#include <glog/logging.h>

#include "ShmNode.h"

int main(int argc, char* argv[])
{
  google::InitGoogleLogging(argv[0]);
  google::ParseCommandLineFlags(&argc, &argv, true);

  FLAGS_minloglevel = google::INFO;
  FLAGS_logtostderr = true;
  FLAGS_colorlogtostderr = true;

  Shm shm1("test");
  shm1.shm_open();
  std::vector<double*> values;

  struct structWorldKeys* world_key = world_keys;
  double k = 5.;

  while (world_key->key != nullptr)
  {
    LOG(WARNING) << "Setting up workd key: "
        << world_key->key << "[" << world_key->size << "]";

    int nval = world_key->size;
    double* pr = shm1.shm_set_ptr(world_key->key, nval);

    for (int i = 0; i < nval; i++)
    {
      values.emplace_back(pr + i);
    }
    
    world_key++;
    LOG(WARNING) << "while";
  }

  for (auto& value: values)
    *value = k++;

  double* a = shm1.shm_get_ptr("time");
  double* b = shm1.shm_get_ptr("position");
  LOG(INFO) << *a;

  for (int i = 0; i < world_keys[1].size; i++)
    LOG(INFO) << b[i];

  return 0;
}
