#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { if (this != &other) {} return *this; }

void PmergeMe::printContainer(const std::vector<int>& vec) const
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << " ";
		if (i > 25)
		{
			std::cout << "[...]";
			break ;
		}
	}
	std::cout << std::endl;
}

void PmergeMe::printContainer(const std::deque<int>& deq) const
{
	for (size_t i = 0; i < deq.size(); ++i)
	{
		std::cout << deq[i] << " ";
		if (i > 25)
		{
			std::cout << "[...]";
			break ;
		}
	}
	std::cout << std::endl;
}


void PmergeMe::sortVector(std::vector<int>& vec)
{
	clock_t start = clock();
	mergeInsertSort(vec, 0, vec.size() - 1);
	clock_t end = clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(6) << duration << " us" << std::endl;
}

void PmergeMe::sortDeque(std::deque<int>& deq)
{
	clock_t start = clock();
	mergeInsertSort(deq, 0, deq.size() - 1);
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " <<  std::fixed << std::setprecision(6) << duration << " us" << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int>& container, int start, int end)
{
	if (end - start <= 15)
	{
		for (int i = start + 1; i <= end; ++i)
		{
			int key = container[i];
			int j = i - 1;
			while (j >= start && container[j] > key)
			{
				container[j + 1] = container[j];
				j--;
			}
			container[j + 1] = key;
		}
	}
	else
	{
		int mid = (start + end) / 2;
		mergeInsertSort(container, start, mid);
		mergeInsertSort(container, mid + 1, end);
		merge(container, start, mid, end);
	}
}

void PmergeMe::mergeInsertSort(std::deque<int>& container, int start, int end)
{
	if (end - start <= 15)
	{
		for (int i = start + 1; i <= end; i++)
		{
			int key = container[i];
			int j = i - 1;
			while (j >= start && container[j] > key)
			{
				container[j + 1] = container[j];
				j--;
			}
			container[j + 1] = key;
		}
	}
	else
	{
		int mid = (start + end) / 2;
		mergeInsertSort(container, start, mid);
		mergeInsertSort(container, start, mid);
		merge(container, start, mid, end);
	}
}

void PmergeMe::merge(std::vector<int>& container, int start, int mid, int end)
{
	std::vector<int> left(container.begin() + start, container.begin() + mid + 1);
	std::vector<int> right(container.begin() + mid + 1, container.begin() + end + 1);
	size_t i = 0, j = 0, k = start;

	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			container[k] = left[i];
			i++;
		} else
		{
			container[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left.size())
	{
		container[k] = left[i];
		i++;
		k++;
	}

	while (j < right.size())
	{
		container[k] = right[j];
		j++;
		k++;
	}
}

void PmergeMe::merge(std::deque<int>& container, int start, int mid, int end)
{
	std::deque<int> left(container.begin() + start, container.begin() + mid + 1);
	std::deque<int> right(container.begin() + mid + 1, container.begin() + end + 1);
	size_t i = 0, j = 0, k = start;

	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			container[k] = left[i];
			i++;
		}
		else
		{
			container[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left.size())
	{
		container[k] = left[i];
		i++;
		k++;
	}

	while (j < right.size())
	{
		container[k] = right[j];
		j++;
		k++;
	}
}
