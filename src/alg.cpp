// Copyright 2021 NNTU-CS

int findFirst(int *arr, int begin, int end, int val) {
  int ans = -1;
  while (begin <= end) {
    int mid = begin + (end - begin) / 2;
    if (arr[mid] >= val) {
      ans = mid;
      end = mid - 1;
    } else {
      begin = mid + 1;
    }
  }
  return ans;
}

int findLast(int *arr, int begin, int end, int val) {
  int ans = -1;
  while (begin <= end) {
    int mid = begin + (end - begin) / 2;
    if (arr[mid] <= val) {
      ans = mid;
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return ans;
}

int countInRange(int *arr, int L, int R, int target) {
  if (L > R) return 0;
  int first = findFirst(arr, L, R, target);
  if (first == -1 || arr[first] != target) return 0;
  int last = findLast(arr, first, R, target);
  return last - first + 1;
}

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
      int leftVal = arr[L];
      int rightVal = arr[R];
      if (leftVal == rightVal) {
        int n = R - L + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int leftCnt = countInRange(arr, L, R - 1, leftVal);
      int rightCnt = countInRange(arr, L + leftCnt, R, rightVal);
      count += leftCnt * rightCnt;
      L += leftCnt;
      R -= rightCnt;
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
    int need = value - arr[i];
    count += countInRange(arr, i + 1, len - 1, need);
  }
  return count;
}
