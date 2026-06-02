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
        int sum = arr[left] + arr[right];

        if (sum == value) {
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }

            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 0;
            int right_count = 0;

            while (left <= right && arr[left] == left_val) {
                left++;
                left_count++;
            }
            while (right >= left && arr[right] == right_val) {
                right--;
                right_count++;
            }

            count += left_count * right_count;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

static void binarySearchRange(int *arr, int len, int target, int start,
                    int *first, int *last) {
    *first = -1;
    *last = -1;

    int low = start;
    int high = len - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            *first = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (*first == -1) return;

    low = *first;
    high = len - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            *last = mid;
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
        binarySearchRange(arr, len, target, i + 1, &first, &last);

        if (first != -1) {
            count += (last - first + 1);
        }
    }

    return count;
}
