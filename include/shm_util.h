#ifndef shm_util_h_DEFINED
#define shm_util_h_DEFINED

#include "ShmConstants.h"

//static const char sensorShmName[] = "dcmSensor";
//static const char actuatorShmName[] = "dcmActuator";

int vision_shm_create();
int vision_shm_open();
int vision_shm_close();
double *vision_shm_get_ptr(const char *key);
double *vision_shm_set_ptr(const char *key, int nval);

int world_shm_create();
int world_shm_open();
int world_shm_close();
double *world_shm_get_ptr(const char *key);
double *world_shm_set_ptr(const char *key, int nval);

int game_ctrl_shm_create();
int game_ctrl_shm_open();
int game_ctrl_shm_close();
double *game_ctrl_shm_get_ptr(const char *key);
double *game_ctrl_shm_set_ptr(const char *key, int nval);

/*
int sensor_shm_open();
int sensor_shm_close();
double *sensor_shm_get_ptr(const char *key);
double *sensor_shm_set_ptr(const char *key, int nval);

int actuator_shm_open();
int actuator_shm_close();
double *actuator_shm_get_ptr(const char *key);
double *actuator_shm_set_ptr(const char *key, int nval);
*/

#endif
