n = int(input())
x = list(map(int, input().split()))
a = 200000 * [10 ** 6]
for i in range(n):
    a[x[i] - 1] = i + 1
print(a.index(min(a)) + 1)
