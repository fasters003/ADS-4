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
        int lcount = 1;
        int rcount = 1;
        while (arr[left] == arr[left + lcount]) lcount++;
        while (arr[right] == arr[right - rcount]) rcount++;
        count += lcount * rcount;
        left += lcount;
        right -= rcount;
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
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int pos = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] >= target) {
        if (arr[mid] == target) pos = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (pos != -1) {
      int j = pos;
      while (j < len && arr[j] == target) {
        if (j > i) count++;
        j++;
      }
    }
  }
  return count;
}
