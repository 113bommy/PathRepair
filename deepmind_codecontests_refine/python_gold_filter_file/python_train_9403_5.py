n, k = map(int, input().split())
a = list(map(int, input().split()))
print(sum((ai >= max(a[k - 1], 1) for ai in a)))