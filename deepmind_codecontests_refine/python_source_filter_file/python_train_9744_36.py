import math
n, k = map(int, input().split())
arr = list(map(int, input().split()))
s = sum(arr)
x = (s - n*(k-0.5)) / -0.5
print(math.ceil(x))
