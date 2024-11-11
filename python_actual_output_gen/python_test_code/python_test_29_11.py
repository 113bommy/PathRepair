def getMaximumWaterSections(n, nums):
    left = [0] * n
    right = [0] * n

    for i in range(1, n):
        left[i] = left[i - 1] + 1 if nums[i] >= nums[i - 1] else 0

    for i in range(n - 2, 0, -1):
        right[i] = right[i + 1] + 1 if nums[i] >= nums[i + 1] else 0

    maximum = 0
    for i in range(0, n):
        if left[i] + right[i] + 1 > maximum:
            maximum = left[i] + right[i] + 1

    return maximum


if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().rstrip().split()))

    print(getMaximumWaterSections(n, nums))