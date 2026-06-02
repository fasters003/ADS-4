// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int L = 0;
  int R = len - 1;

  while (L < R) {
    int sum = arr[L] + arr[R];
    if (sum == value) {
      if (arr[L] == arr[R]) {
        int n = R - L + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int leftVal = arr[L];
      int rightVal = arr[R];
      int leftCnt = 0;
      int rightCnt = 0;
      do {
        L++;
        leftCnt++;
      } while (L < R && arr[L] == leftVal);
      do {
        R--;
        rightCnt++;
      } while (L <= R && arr[R] == rightVal);
      count += leftCnt * rightCnt;
    } else if (sum < value) {
      L++;
    } else {
      R--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        int first = mid;
        while (first > i + 1 && arr[first - 1] == target) {
          first--;
        }
        int last = mid;
        while (last < len - 1 && arr[last + 1] == target) {
          last++;
        }
        count += last - first + 1;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}
