k, n = map(int, input().split())
*a, = map(int, input().split())
a += [i+k for i in a]
print(min(j-i for i, j in zip(a, a[2:])))