// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;

    while (left < right) {
        int current_sum = arr[left] + arr[right];

        if (current_sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            } else {
                int left_count = 1, right_count = 1;
                while (left + 1 < right && arr[left] == arr[left + 1]) {
                    left++;
                    left_count++;
                }
                while (right - 1 > left && arr[right] == arr[right - 1]) {
                    right--;
                    right_count++;
                }
                count += left_count * right_count;
                left++;
                right--;
            }
        } else if (current_sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

void binarySearchRange(int *arr, int len, int target, int start, int &first, int &last) {
    first = -1;
    last = -1;

    int low = start, high = len - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (first == -1) return;

    low = first;
    high = len - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            last = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; ++i) {
        int target = value - arr[i];
        int first, last;
        binarySearchRange(arr, len, target, i + 1, first, last);

        if (first != -1) {
            count += (last - first + 1);
        }
    }

    return count;
}
