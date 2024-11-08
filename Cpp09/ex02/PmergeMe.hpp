#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void sortVector(std::vector<int>& vec);
		void sortDeque(std::deque<int>& deq);
		void printContainer(const std::vector<int>& vec) const;
		void printContainer(const std::deque<int>& deq) const;

	private:
		void mergeInsertSort(std::vector<int>& container, int start, int end);
		void mergeInsertSort(std::deque<int>& container, int start, int end);
		void merge(std::vector<int>& container, int start, int mid, int end);
		void merge(std::deque<int>& container, int start, int mid, int end);
};

#endif // PMERGEME_HPP
