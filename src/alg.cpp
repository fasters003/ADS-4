// Copyright 2021 NNTU-CS

int searchLeft(int *arr, int left, int right, int target) {
  int res = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      res = mid;
      right = mid - 1;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return res;
}

int searchRight(int *arr, int left, int right, int target) {
  int res = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      res = mid;
      left = mid + 1;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return res;
}

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (i < j && arr[i] + arr[j] == value) {
        count++;
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
      count++;
      int r = right - 1;
      while (r > left && arr[left] + arr[r] == value) {
        count++;
        r--;
      }
      left++;
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
  for (int i = 0; i < len - 1; i++) {
    int target = value - arr[i];
    int first = searchLeft(arr, i + 1, len - 1, target);
    if (first != -1) {
      int last = searchRight(arr, first, len - 1, target);
      count += (last - first + 1);
    }
  }
  return count;
}
