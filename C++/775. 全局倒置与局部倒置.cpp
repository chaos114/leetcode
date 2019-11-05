class Solution {
public:
	bool isIdealPermutation(vector<int>& A) {
		int count_g = 0;
		int count_te = 0;
		for (int i = 1; i < A.size(); i++) {
			if (A[i] < A[i - 1]) count_te++;
		}
		vector<int> B(A.begin(), A.end());
		core(A, B, 0, A.size() - 1, count_g);
		return count_g == count_te;
	}
	void  core(vector<int>& A, vector<int>& B, int left, int right, int& count) {
		if (left >= right) return;
		int mid = (left + right) / 2;
		core(A, B, left, mid, count);
		core(A, B, mid + 1, right, count);
		merge(A, B, left, mid, right, count);
	}
	void merge(vector<int>& A, vector<int>& B, int left, int mid, int right, int& count) {
		int leftcur = left;
		int rightcur = mid + 1;
		int cur = left;
		while (cur <= right) {
			if (leftcur > mid) {
				B[cur++] = A[rightcur++];
			}
			else if (rightcur > right) {
				B[cur++] = A[leftcur++];
				count += right - mid;

			}
			else {
				if (A[leftcur] > A[rightcur]) {
					B[cur++] = A[rightcur++];
				}
				else {
					count += rightcur - mid - 1;
					B[cur++] = A[leftcur++];
				}
			}
		}
		for (int i = left; i <= right; i++) {
			A[i] = B[i];
		}

	}
};