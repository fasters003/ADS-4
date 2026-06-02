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
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }
      int cntL = 1;
      int cntR = 1;
      while (left + cntL < right && arr[left] == arr[left + cntL]) {
        cntL++;
      }
      while (right - cntR > left && arr[right] == arr[right - cntR]) {
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
    int lo = i + 1;
    int hi = len - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (arr[mid] >= target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if (lo < len && lo > i && arr[lo] == target) {
      int start = lo;
      hi = len - 1;
      while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] <= target) {
          if (arr[mid] == target) start = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      int j = start;
      while (j >= i + 1 && arr[j] == target) {
        count++;
        j--;
      }
    }
  }
  return count;
}
