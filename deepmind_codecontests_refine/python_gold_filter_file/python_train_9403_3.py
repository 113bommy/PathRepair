n, k = map(int, input().split())
a = list(map(int, input().split()))
print(sum(i and i >= a[k - 1] for i in a))
