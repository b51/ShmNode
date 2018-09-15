/*************************************************************************
*
*              Author: b51
*                Mail: b51live@gmail.com
*            FileName: ShmNode.h
*
*          Created On: Fri 14 Sep 2018 08:15:04 PM CST
*     Licensed under The MIT License [see LICENSE for details]
*
************************************************************************/

#ifndef SHM_NODE_H_
#define SHM_NODE_H_

#include "cartographer/common/make_unique.h"

#include "ShmConstants.h"
#include "Shm.h"

namespace IKid
{

class ShmNode
{
public:
  ShmNode();
  ~ShmNode();

  void Init();
  double* WorldShmSetPtr(const char* key, const int nval)
  {
    return world_shm_->shm_set_ptr(key, nval);
  }

  double* WorldShmGetPtr(const char* key)
  {
    return world_shm_->shm_get_ptr(key);
  }

private:
  std::unique_ptr<Shm> world_shm_;
};

} // namespace IKid

#endif
