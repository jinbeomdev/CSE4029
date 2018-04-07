/*
Student ID : 2013113504
Studnet Name : KIM JIN BEOM

Problem 1
1)Find min and max at the same time
2)Generate 1000 random positive integers in the range 1~100000.
-Use Minimum() function you have learned at the lecture and write Maximum() function in a similar way to print min and max values.
-Use FindMinMax() function you have learned at the lecture to find max and min values.

output : 
FIND MINIMUM : 29
FIND MAXIMUM : 32758
FIND MIN MAX : 29, 32758
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void CompareTwoValue(const int a, const int b, int &small, int &large) {
	if (a > b) {
		small = b;
		large = a;
	}
	else {
		small = a;
		large = b;
	}
}

pair<int, int> FindMinMax(const vector<int> &random_numbers) {
	int min_value = random_numbers[0], max_value = random_numbers[0];

	for (int i = 1; i < (int)random_numbers.size() - 1; i += 2) {
		int small, large;

		CompareTwoValue(random_numbers[i], random_numbers[i + 1],
			              small, large);

		if (small < min_value) {
			min_value = small;
		}

		if (large > max_value) {
			max_value = large;
		}
	}

	return { min_value, max_value };
}

int FindMaximum(const vector<int> &random_numbers) {
	int max_value = random_numbers[0];

	for (int i = 1; i < (int)random_numbers.size(); i++) {
		if (max_value < random_numbers[i]) {
			max_value = random_numbers[i];
		}
	}

	return max_value;
}

int FindMinimum(const vector<int> &random_numbers) {
	int min_value = random_numbers[0];
	
	for (int i = 1; i < (int)random_numbers.size(); i++) {
		if (min_value > random_numbers[i]) {
			min_value = random_numbers[i];
		}
	}

	return min_value;
}

void PrintResult(int const result_find_min,
                 int const result_find_max,
	               const pair<int, int> reuslt_find_min_max) {
	cout << "FIND MINIMUM : " << result_find_min << endl <<
	        "FIND MAXIMUM : " << result_find_max << endl <<
		      "FIND MIN MAX : " << reuslt_find_min_max.first 
		                        << ", "
		                        << reuslt_find_min_max.second << endl;
}

int main() {
	const int rand_max = 100000;
	const int random_numbers_size = 1000;
	vector<int> random_numbers = vector<int>(random_numbers_size, 0);

	for (int i = 0; i < random_numbers_size; i++) {
		random_numbers[i] = rand() % rand_max + 1;
	}

	int result_find_min = FindMinimum(random_numbers);
	int result_find_max = FindMaximum(random_numbers);
	pair<int, int> result_find_min_max = FindMinMax(random_numbers);

	PrintResult(result_find_min , result_find_max,
		          result_find_min_max);
	system("pause");
}