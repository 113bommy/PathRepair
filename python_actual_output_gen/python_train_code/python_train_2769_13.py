n = int(input())
a = [int(i) for i in input().split()]
s = 0
for i in range(n - 1):
    s += a[i] * (i + 2)
s += a[-1] * n
print(s)