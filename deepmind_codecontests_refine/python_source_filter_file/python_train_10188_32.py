n = int(input())
p = list(map(int, input().split()))
l = [0] * n
for i in range(n):
    l[p[i] - 1] = i
a = [3 * 10 ** 4 * (i + 1) for i in range(n)]
b = [3 * 10 ** 4 * (n - i - 1) + l[i] for i in range(n)]
print(*a)
print(*b)