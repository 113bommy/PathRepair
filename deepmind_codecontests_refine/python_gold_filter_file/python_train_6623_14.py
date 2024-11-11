n, k, x = map(int, input().split())
a = list(map(int, input().split()))
for i in range(-1, -k - 1, -1):
    a[i] = x
print(sum(a))