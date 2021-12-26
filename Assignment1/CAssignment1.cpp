/******************************************************************************
GPU Computing / GPGPU Praktikum source code.

******************************************************************************/

#include "CAssignment1.h"

#include "CSimpleArraysTask.h"
#include "CMatrixRotateTask.h"

#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// CAssignment1

bool CAssignment1::DoCompute()
{
	// Task 1: simple array addition.
	cout << "Running vector addition example..." << endl << endl;

	//this Array supports 1D, 2D or 3D Work-group sizes
	//for the 1st Task only the first component is relevant
	//the vector size is the integer argument of the constructor of the task

	//4 different work-group sizes
	{
		size_t localWorkSize[3] = {128, 1, 1};
		CSimpleArraysTask task(1048576);
		RunComputeTask(task, localWorkSize);
	}
	{
		size_t LocalWorkSize[3] = {256, 1, 1};
		CSimpleArraysTask task(1048576);
		RunComputeTask(task, LocalWorkSize);
	}
	{
		size_t LocalWorkSize[3] = {512, 1, 1 };
		CSimpleArraysTask task(1048576);
		RunComputeTask(task, LocalWorkSize);
	}
	{
		size_t LocalWorkSize[3] = {1024, 1, 1 };
		CSimpleArraysTask task(1048576);
		RunComputeTask(task, LocalWorkSize);
	}

	//4 different array sizes
	{
		size_t LocalWorkSize[3] = {512, 1, 1 };
		CSimpleArraysTask task(1048576);
		RunComputeTask(task, LocalWorkSize);
	}
	{
		size_t LocalWorkSize[3] = {512, 1, 1 };
		CSimpleArraysTask task(4*1048576);
		RunComputeTask(task, LocalWorkSize);
	}
	{
		size_t LocalWorkSize[3] = {512, 1, 1 };
		CSimpleArraysTask task(10*1048576);
		RunComputeTask(task, LocalWorkSize);
	}
	{
		size_t LocalWorkSize[3] = {512, 1, 1 };
		CSimpleArraysTask task(20*1048576);
		RunComputeTask(task, LocalWorkSize);
	}

	// Task 2: matrix rotation.
	std::cout << std::endl << std::endl << "Running matrix rotation example..." << std::endl << std::endl;
	{
		size_t LocalWorkSize[3] = {32, 16, 1};
		CMatrixRotateTask task(2048, 1025);
		RunComputeTask(task, LocalWorkSize);
	}

	return true;
}

///////////////////////////////////////////////////////////////////////////////
