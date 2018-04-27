/*
Student ID : 2013113504
Studnet Name : KIM JIN BEOM

Question 2:
Tree Cutting Problem

����̴� ���� M���Ͱ� �ʿ��ϴ�. ��ó�� ������ ������ ���� ��� ���ع��ȱ�
������, ���ο� ���� �㰡�� ��û�ߴ�. ���δ� ����̳� �� ��ó�� ���� �� �ٿ�
���� ���� �㰡�� ���־���, ����̴� ���� ������ ���� ���ܱ⸦ �̿��ؼ� ������
���� ���̴�.

�������ܱ�� ������ ���� �����Ѵ�. ����, ����̴� ���ܱ⿡ ���� H�� �����ؾ�
�Ѵ�. ���̸� �����ϸ� �鳯�� �����κ��� H���� ���� �ö󰣴�. �� ����, �� �ٿ�
������ �ִ� ������ ��� �����ع�����. ����, ���̰� H���� ū ������ H ����
�κ��� �߸� ���̰�, ���� ������ �߸��� ���� ���̴�. ���� ���, �� �ٿ� ������
�ִ� ������ ���̰� 20, 15, 10, 17�̶�� ����. ����̰� ���̸� 15�� �����ߴٸ�,
������ �ڸ� ���� ���̴� 15, 15, 10, 15�� �� ���̰�, ����̴� ���̰� 5�� ������
2�� ������ ��� ���� �� ���̴�. (�� 7���͸� ���� ��� ����)

����̴� ȯ�濡 �ſ� ������ ���� ������, ������ �ʿ��� ��ŭ�� ������ ����������
�Ѵ�. �� ��, ��� M������ ������ ���� �������� ���ؼ� ���ܱ⿡ ������ �� �ִ�
������ �ִ밪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

Input :
4 7
20 15 10 17

Output:
15

������ ��... �׽�Ʈ ���̽��� �ʹ� ������ �ƴϿ�.
*/
#include <iostream>

using namespace std;

const int kInf = 10e6;
const int KMaxTree = 100;

int main() {
	int N, M;
	int result;
	int height_trees[KMaxTree];

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> height_trees[i];
	}

	int left = 0, right = kInf, mid;
	
	while (left <= right) {
		int total_cutted_height = 0;

		mid = (left + right) / 2;

		for (int i = 0; i < N; i++) {
			if (mid < height_trees[i]) {
				total_cutted_height += (height_trees[i] - mid);
			}
		}

		if (total_cutted_height < M) {
			right = mid - 1;
		}
		else if (total_cutted_height > M) {
			left = mid + 1;
		}
		else {
			break;
		} 
	}

	cout << mid << endl;
	system("pause");
}