n, k, x = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n - 1 - k, n):
    a[i] = x
print(sum(a))