// TO DO: Add kernel code function
__kernel void VecAdd(__global const int* a, __global const int* b, __global int* c, int numElements)
{
	int GID = get_global_id(0); //Get the global thread ID
	if (GID < numElements) //check if the thread ID is not greater than the number of elements of our vector
	{ 
		c[GID] = a[GID] + b[numElements - GID - 1];
	}
}


