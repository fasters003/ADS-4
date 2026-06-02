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

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        int first = mid;
        while (first > i && arr[first - 1] == target) {
          first--;
        }
        int last = mid;
        while (last < len - 1 && arr[last + 1] == target) {
          last++;
        }
        count += (last - first + 1);
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
