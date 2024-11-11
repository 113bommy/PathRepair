import sys
import math

n = int(input())
a = list(map(int, sys.stdin.readline().split()))
newA = []
arr = [a[0]]
ans = 0
for i in range(1, len(a)):
    if a[i] > a[i-1]:
        arr.append(a[i])
    else:
        newA.append(arr)
        arr = [a[i]]
if len(arr):
    newA.append(arr)
for i in range(len(newA)):
    ans = max(ans, len(newA[i]))
for i in range(1, len(newA)):
    if len(newA[i]) > 1 and  newA[i-1][-1] > newA[i][1]:
        ans = max(len(newA[i]) + len(newA[i-1]) - 1, ans)
    if len(newA[i-1]) > 1 and newA[i - 1][-2] > newA[i][0]:
        ans = max(len(newA[i]) + len(newA[i - 1]) - 1, ans)
print(ans)