#include "shm_util.h"

#include <boost/interprocess/managed_shared_memory.hpp>
using namespace boost::interprocess;

static int shmSize = 65536;

/*
managed_shared_memory *sensorShm = NULL;
managed_shared_memory *actuatorShm = NULL;
*/
managed_shared_memory* visionShm = nullptr;
managed_shared_memory* worldShm = nullptr;
managed_shared_memory* gctrlShm = nullptr;

static managed_shared_memory *shm_create(const char* name) {
  // First clear out old shm
  shared_memory_object::remove(name);
  // Get Boost::interprocess managed shared memory object
  managed_shared_memory *shm;
  shm = new managed_shared_memory(open_or_create,
				  name, shmSize);
  return shm;
}

static managed_shared_memory *shm_open(const char* name) {
  managed_shared_memory *shm;
  shm = new managed_shared_memory(open_only,
          name);
          //name, shmSize);
  return shm;
}


static void shm_destroy(const char* name) {
  shared_memory_object::remove(name);
}

static double *shm_get_ptr(managed_shared_memory *shm, const char *key) {
  // Find key in shm
  std::pair<double*, std::size_t> ret;
  ret = shm->find<double>(key);
  double *pr = ret.first;
  return pr;
}

static double *shm_set_ptr(managed_shared_memory *shm,
			   const char *key, int nval) {
  // Check if key exists in shm
  std::pair<double*, std::size_t> ret;
  ret = shm->find<double>(key);
  double *pr = ret.first;
  int n = ret.second;
  if (pr) {
    if (n == nval) {
      return pr;
    }
    else {
      shm->destroy_ptr(pr);
    }
  }
  return shm->construct<double>(key)[nval](0);
}

/***** vision shm *****/
int vision_shm_create() {
  visionShm = shm_create(visionShmName);
  if (worldShm == nullptr) {
    return -1;
  }
  return 0;
}

int vision_shm_open() {
  visionShm = shm_open(visionShmName);
  if (visionShm == nullptr) {
    return -1;
  }
  return 0;
}

int vision_shm_close() {
  if (visionShm) {
    delete visionShm;
  }
  shm_destroy(visionShmName);
  return 0;
}

double *vision_shm_get_ptr(const char *key) {
  return shm_get_ptr(visionShm, key);
}

double *vision_shm_set_ptr(const char *key, int nval) {
  return shm_set_ptr(visionShm, key, nval);
}
/*---- vision shm ----*/

/***** world shm *****/
int world_shm_create() {
  worldShm = shm_create(worldShmName);
  if (worldShm == nullptr) {
    return -1;
  }
  return 0;
}

int world_shm_open() {
  worldShm = shm_open(worldShmName);
  if (worldShm == nullptr) {
    return -1;
  }
  return 0;
}

int world_shm_close() {
  if (worldShm) {
    delete worldShm;
  }
  shm_destroy(worldShmName);
  return 0;
}

double *world_shm_get_ptr(const char *key) {
  printf("%s\n", key);
  if (worldShm == nullptr)
    printf("nullptr\n");
  else
    printf("ojbk\n");
  return shm_get_ptr(worldShm, key);
}

double *world_shm_set_ptr(const char *key, int nval) {
  return shm_set_ptr(worldShm, key, nval);
}
/*---- world shm ----*/

/***** game ctrl shm *****/
int game_ctrl_shm_create() {
  gctrlShm = shm_create(gctrlShmName);
  if (gctrlShm == nullptr) {
    return -1;
  }
  return 0;
}

int game_ctrl_shm_open() {
  gctrlShm = shm_open(gctrlShmName);
  if (gctrlShm == nullptr) {
    return -1;
  }
  return 0;
}

int game_ctrl_shm_close() {
  if (gctrlShm) {
    delete gctrlShm;
  }
  shm_destroy(gctrlShmName);
  return 0;
}

double *game_ctrl_shm_get_ptr(const char *key) {
  return shm_get_ptr(gctrlShm, key);
}

double *game_ctrl_shm_set_ptr(const char *key, int nval) {
  return shm_set_ptr(gctrlShm, key, nval);
}
/*---- game ctrl shm ----*/

/*
int sensor_shm_open() {
  sensorShm = shm_create(sensorShmName);
  if (sensorShm == NULL) {
    return -1;
  }
  return 0;
}

int sensor_shm_close() {
  if (sensorShm) {
    delete sensorShm;
  }
  shm_destroy(sensorShmName);
  return 0;
}

double *sensor_shm_get_ptr(const char *key) {
  return shm_get_ptr(sensorShm, key);
}

double *sensor_shm_set_ptr(const char *key, int nval) {
  return shm_set_ptr(sensorShm, key, nval);
}

int actuator_shm_open() {
  actuatorShm = shm_create(actuatorShmName);
  if (actuatorShm == NULL) {
    return -1;
  }
  return 0;
}

int actuator_shm_close() {
  if (actuatorShm) {
    delete actuatorShm;
  }
  shm_destroy(actuatorShmName);
  return 0;
}

double *actuator_shm_get_ptr(const char *key) {
  return shm_get_ptr(actuatorShm, key);
}

double *actuator_shm_set_ptr(const char *key, int nval) {
  return shm_set_ptr(actuatorShm, key, nval);
}
*/
