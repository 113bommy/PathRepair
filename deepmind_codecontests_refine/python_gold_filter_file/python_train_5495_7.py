k, n = map(int, input().split())
a = list(map(int, input().split()))
a += [k + a[0]]
print(k - max([a[i + 1] - a[i] for i in range(n)]))