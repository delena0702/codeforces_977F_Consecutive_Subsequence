#include <iostream>

void show(int* back, unsigned int n)
{
	if (back[n] < 0)
	{
		std::cout << n + 1 << " ";
		return;
	}

	show(back, back[n]);
	std::cout << n + 1 << " ";
}

int main(void)
{
	unsigned int n;
	unsigned int* data, * d;
	int* back;

	std::cin >> n;

	data = new unsigned int[n];
	d = new unsigned int[n];
	back = new int[n];

	for (unsigned int i = 0; i < n; i++)
		std::cin >> data[i];

	d[0] = 1;
	back[0] = -1;

	for (unsigned int i = 1; i < n; i++)
	{
		int j;

		for (j = i - 1; j >= 0; j--)
		{
			if (data[i] == data[j] + 1)
			{
				d[i] = d[j] + 1;
				back[i] = j;
				break;
			}
		}

		if (j < 0)
		{
			d[i] = 1;
			back[i] = -1;
		}
	}

	unsigned int max_ind = n - 1;
	unsigned int max_val = d[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		if (d[i] > max_val)
		{
			max_ind = i;
			max_val = d[i];
		}
	}

	std::cout << max_val << std::endl;
	show(back, max_ind);

	delete[] data;
	delete[] d;
	delete[] back;

	return 0;
}