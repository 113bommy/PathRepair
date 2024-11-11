from math import ceil

n = int(input())
m = int(input())
arr = list()

for _ in range(int(n)):
    arr.append(int(input()))

arr = sorted(arr)

possible = 0
for a in arr:
    possible = possible + (arr[-1] - a)

if possible >= m:
    print(arr[-1], arr[-1] + m)
else:
    print(int(ceil((m - possible) / len(arr) + 0.5)) + arr[-1], arr[-1] + m)
