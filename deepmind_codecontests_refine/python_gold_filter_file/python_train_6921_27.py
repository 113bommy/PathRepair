#!/usr/bin/python3.4

# SIZE = 10
# matrix = [[0] * SIZE for i in range(SIZE)]
# arr = [0] * SIZE

n = int(input())
arr = list(map(int, input().split()))
arr.sort()
s = 0
ans = 0
for val in arr:
    if val >= s:
        ans += 1
        s += val
print(ans)
