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

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int k = 0; k < 5; k++) {
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
      int leftVal = arr[left];
      int rightVal = arr[right];
      int cntL = 1;
      while (left + cntL < right && arr[left + cntL] == leftVal) {
        cntL++;
      }
      int cntR = 1;
      while (right - cntR > left && arr[right - cntR] == rightVal) {
        cntR++;
      }
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
    int first = binarySearchFirst(arr, i + 1, len - 1, target);
    if (first != -1) {
      int last = binarySearchLast(arr, first, len - 1, target);
      count += last - first + 1;
    }
  }
  return count;
}
