n, n1, n2 = map(int, input().split())
a = sorted(list(map(int, input().split())))
print(a[n1] - a[n1 - 1])