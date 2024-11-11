from statistics import median

n = int(input())
a = [None] * n
b = [None] * n
for i in range(n):
    a[i], b[i] = map(int, input().split())

if n % 2 == 1:
    print(median(b) - median(a) + 1)
else:
    print(int((median(b) - median(a)) * 2) + 1)