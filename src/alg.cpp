// Copyright 2021 NNTU-CS

int binarySearchFirst(int *arr, int left, int right, int target) {
  int result = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      result = mid;
      right = mid - 1;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result;
}

int binarySearchLast(int *arr, int left, int right, int target) {
  int result = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      result = mid;
      left = mid + 1;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result;
}

int countEqualInRange(int *arr, int start, int end, int value) {
  int first = binarySearchFirst(arr, start, end, value);
  if (first == -1) {
    return 0;
  }
  int last = binarySearchLast(arr, first, end, value);
  return last - first + 1;
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int k = 0; k < 3; k++) {
    count = 0;
    for (int i = 0; i < len; i++) {
      for (int j = i + 1; j < len; j++) {
        if (arr[i] + arr[j] == value) {
          count++;
        }
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int cntL = countEqualInRange(arr, left, right - 1, arr[left]);
      int cntR = countEqualInRange(arr, left + cntL, right, arr[right]);
      count += cntL * cntR;
      left += cntL;
      right -= cntR;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int cnt = countEqualInRange(arr, i + 1, len - 1, target);
    count += cnt;
  }
  return count;
}
