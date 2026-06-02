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
    int left = i + 1;
    int right = len - 1;
    int found = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        found = 1;
        int l = mid;
        int r = mid;
        while (l > i && arr[l - 1] == target) l--;
        while (r < len - 1 && arr[r + 1] == target) r++;
        count += r - l + 1;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (!found) {
      left = i + 1;
      right = len - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        left++;
      }
    }
  }
  return count;
}
