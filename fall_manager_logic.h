/*
 * accelleration_logic.h
 *
 *  Created on: Mar 28, 2014
 *      Author: ross
 */

#ifndef FALL_MANAGER_LOGIC_H_
#define FALL_MANAGER_LOGIC_H_

#define SAMPLE_ARRAY_DEPTH	500

typedef union
{
	struct
	{
		int8_t x;
		int8_t y;
		int8_t z;
	} xyzData[SAMPLE_ARRAY_DEPTH];
	int8_t rawData[3 * SAMPLE_ARRAY_DEPTH];
} sAccellerometerData_t;

int fall_mng_thread_pid;

void initFallManager(void);

#endif /* FALL_MANAGER_LOGIC_H_ */
