n, k = map(int, input().split())
a = list(map(int, input().split()))
print(sum((ai >= a[k - 1] for ai in a)))
