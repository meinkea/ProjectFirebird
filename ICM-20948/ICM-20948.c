#include <stdio.h>
#include "ICM-20948.h"

// Public Methods
static int add(struct tagDriveInstance *this, int num) {
	return this->setting_1 + num;
}

static int 

// Constructor Methods
static struct tagDriveInstance NEW(int in1, int in2, int in3, int in4) {
	return (struct tagDriveInstance) {
		.setting_1 = in1,
		.setting_2 = in2,
		.setting_3 = in3,
		.setting_4 = in4
	};
	
}
