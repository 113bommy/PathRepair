n = int(input())
a = [int(i) for i in input().split()]
c0, c1 = 0, 0
for i in range(1, n // 2 + 1):
    c0 += abs(2 * i - 1 - a[i - 1])
    c1 += abs(2 * i - a[i - 1])
print(min(c0, c1))
