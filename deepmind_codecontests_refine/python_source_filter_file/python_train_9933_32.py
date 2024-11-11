[n, k] = [int(item) for item in input().split(' ')]
heights = [int(item) for item in input().split(' ')]

min_index = 0
min_sum = sum(heights[:k])
running_sum = min_sum
for i in range(k, n):
    running_sum -= heights[i - k]
    running_sum += heights[i]
    if running_sum < min_sum:
        min_sum = running_sum
        min_index = i - k + 2
print(min_index)
