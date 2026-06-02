// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (i != j && arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count / 2;
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
            int left_cnt = 0;
            int right_cnt = 0;

            while (left < right && arr[left] == left_val) {
                left++;
                left_cnt++;
            }

            while (left <= right && arr[right] == right_val) {
                right--;
                right_cnt++;
            }

            count += left_cnt * right_cnt;
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

    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int first = -1;
        int last = -1;

        int low = i + 1;
        int high = len - 1;
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

        if (first == -1) continue;

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

        count += last - first + 1;
    }

    return count;
}
