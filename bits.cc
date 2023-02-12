#include <stdio.h>

void print3dPoint(int number)
{
	int x,y,z, mask;
	//x:
	mask = 0x3ff00000;
	x = number & mask;
	x = (x >> 20);

	//y:
	mask = 0x000ffc00;
	y = number & mask;
	y = (y >> 10);

	//z:
	mask = 0x000003ff;
	z = number & mask;

	//print:
	printf("(%d, %d, %d)\n", x, y, z);
}

int swapBytes(int num)
{
	//break into bytes:
	int b1, b2, b3, b4, mask, result;

	mask = 0xff000000;
	b1 = num & mask;

	mask = 0x00ff0000;
	b2 = num & mask;

	mask = 0x0000ff00;
	b3 = num & mask;

	mask = 0x000000ff;
	b4 = num & mask;

	//swap b1 and b2:
	b1 = (b1 >> 8);
	mask = 0x00ff0000;
	b1 = b1 & mask;
	b2 = (b2 << 8);
	result = b1 | b2;

	//swap b3 and b4:
	b3 = (b3 >> 8);
	b4 = (b4 << 8);
	result = result | b3 | b4;

	return result;
}

int countGroups(int num)
{
	int groups = 0;
	int flag = 0;
	unsigned int mask = 0x80000000;
	for (int i = 32; i > 0; i--)
	{
		if ((num & mask) != 0 && flag == 0)
		{
			groups++;
			flag = 1;
		}
		else if ((num & mask) == 0)
		{
			flag = 0;
		}
		mask = mask >> 1;
	}

	return groups;
}
