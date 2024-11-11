n, k = [int(item) for item in input().split()]
result = [0]*n
if k != n:
    result[0] = n
else:
     result[n-1] = n
l = 1
for i in range(1, n-1):
    if i <= k:
        result[i] = i+1
    else:
        result[-l] = n - i+1
        l += 1
if result.__contains__(0):
    result[result.index(0)] = 1
if n == 1 == k or k == n-1:
    print('-1')
else:
    print(' '.join(map(str, result)))