// Copyright 2021 NNTU-CS

int searchLeft(int *arr, int left, int right, int target) {
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

int searchRight(int *arr, int left, int right, int target) {
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
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] > value) {
                break;
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
        
        if (sum < value) {
            left++;
        } else if (sum > value) {
            right--;
        } else {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += (n * (n - 1)) / 2;
                break;
            } else {
                int countLeft = 1;
                int countRight = 1;
                
                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    countLeft++;
                    left++;
                }
                
                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    countRight++;
                    right--;
                }
                
                count += countLeft * countRight;
                left++;
                right--;
            }
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
            int last = searchRight(arr, i + 1, len - 1, target);
            count += (last - first + 1);
        }
    }
    return count;
}
