from collections import defaultdict
n = int(input())
a = [int(i) for i in input().split()]
d = defaultdict(int)
for i in range(n-1):
    for j in range(i+1, n):
        sum = a[i] + a[j]
        d[sum] += 1
print(max(d.values()))