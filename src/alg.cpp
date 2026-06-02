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
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int k = right - left + 1;
        count += (k * (k - 1)) / 2;
        break;
      } else {
        int leftDup = 1;
        int rightDup = 1;
        while (left + leftDup < right && arr[left] == arr[left + leftDup]) {
          leftDup++;
        }
        while (right - rightDup > left && arr[right] == arr[right - rightDup]) {
          rightDup++;
        }
        count += leftDup * rightDup;
        left += leftDup;
        right -= rightDup;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearch(int *arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int i = 0;
  while (i < len - 1) {
    int target = value - arr[i];
    int found = binarySearch(arr, i + 1, len - 1, target);
    if (found != -1) {
      int leftCount = 1;
      int rightCount = 1;
      while (i + leftCount < len && arr[i] == arr[i + leftCount]) {
        leftCount++;
      }
      while (found + rightCount < len && arr[found] == arr[found + rightCount]) {
        rightCount++;
      }
      if (arr[i] == arr[found]) {
        count += (leftCount * (leftCount - 1)) / 2;
      } else {
        count += leftCount * rightCount;
      }
      i += leftCount;
    } else {
      i++;
    }
  }
  return count;
}
