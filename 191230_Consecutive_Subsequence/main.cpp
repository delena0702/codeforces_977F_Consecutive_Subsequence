#include <iostream>

int main(void)
{
	unsigned int n, * data, * dp, max_ind, max_dp;
	unsigned int* back;

	std::cin >> n;

	data = new unsigned int[n];
	dp = new unsigned int[n];
	back = new unsigned int[n];

	for (unsigned int i = 0; i < n; i++)
		std::cin >> data[i];

	dp[n - 1] = 1;
	back[n - 1] = -1;
	max_ind = n - 1;
	max_dp = 1;

	for (unsigned int i = n - 2; i != -1; i--)
	{
		unsigned int ind;

		for (ind = i + 1; ind < n; ind++)
		{
			if (data[i] == data[ind] - 1)
				break;
		}

		if (ind == n)
		{
			dp[i] = 1;
			back[i] = -1;
		}

		else
		{
			dp[i] = dp[ind] + 1;
			back[i] = ind;
		}

		if (dp[i] > max_dp)
		{
			max_ind = i;
			max_dp = dp[i];
		}
	}

	std::cout << max_dp << std::endl;

	for (unsigned int ind = max_ind; ind < n; ind = back[ind])
		std::cout << ind + 1 << " ";

	delete[] data;
	delete[] dp;
	delete[] back;

	return 0;
}