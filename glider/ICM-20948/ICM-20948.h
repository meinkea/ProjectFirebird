//
// ICM-20948.h
//

#ifndef ICM_20948_H
#define ICM_20948_H


#include <stdio.h>
#include "inc/ICM_20948_BANKS.h"
#include "inc/ICM_20948_REGISTERS.h"


// Struct containing varaible memebers and function memebers
struct tagDriveInstance {
	// Instance Variables
	unsigned int setting_1;
	unsigned int setting_2;
	unsigned int setting_3;
	unsigned int setting_4;

	struct BANKS banks;

	// Instance Methods
	int (*add)(struct tagDriveInstance * this, int num);
};

// Global Constant Struct containing class variables and methods
extern const struct tagMyDriverClass {
	// Class Constructor
	struct tagDriveInstance (*new)(int Set1, int Set2, int Set3, int Set4);

	// Class Methods
	
	// Class Variables

} DriverClass;

#endif // ICM_20948_H


