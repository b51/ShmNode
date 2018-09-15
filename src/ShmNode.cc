/*************************************************************************
*
*              Author: b51
*                Mail: b51live@gmail.com
*            FileName: ShmNode.cc
*
*          Created On: Fri 14 Sep 2018 08:14:25 PM CST
*     Licensed under The MIT License [see LICENSE for details]
*
************************************************************************/

#include "ShmNode.h"

namespace IKid
{
using namespace cartographer;

ShmNode()
{
}

~ShmNode()
{
  if (world_shm_)
    world_shm_.reset(nullptr);
}

void ShmNode::Init()
{
  world_shm_ = common::make_unique<Shm>(std::string(WorldShmName));
  if (world_shm_ == nullptr)
    LOG(WARNING) << "world_shm_ init failed";
}

} // namespace IKid
