[n, w] = list(map(int, input().split()))
arr = list(map(int, input().split()))

tmpArr = list(reversed(sorted(arr)))
x = max(tmpArr[0] / 2, tmpArr[n])
print(min(3 * x * n, w))