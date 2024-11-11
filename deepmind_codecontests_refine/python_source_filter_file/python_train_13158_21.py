import math

[n, k] = [int(item) for item in input().split(' ')]
arr = [int(item) for item in input().split(' ')]

pre = sum(arr[:k])
left_sum = [pre]
left_index = [0]
for i in range(k, n - k):
    pre -= arr[i - k]
    pre += arr[i]
    if pre > left_sum[-1]:
        left_sum.append(pre)
        left_index.append(i)
    else:
        left_sum.append(left_sum[-1])
        left_index.append(left_index[-1])

pre = sum(arr[n - k:])
right_sum = [pre]
right_index = [n - k]
for i in reversed(range(k, n - k)):
    pre -= arr[i + k]
    pre += arr[i]
    if pre >= right_sum[-1]:
        right_sum.append(pre)
        right_index.append(i)
    else:
        right_sum.append(right_sum[-1])
        right_index.append(right_index[-1])

right_sum.reverse()
right_index.reverse()
max_sum = -1 * math.inf
max_index = -1
for i in range(len(right_sum)):
    s = right_sum[i] + left_sum[i]
    if s > max_sum:
        max_sum = s
        max_index = i

print(left_index[max_index] + 1, right_index[max_index] + 1)
