n, k, s = map(int, input().split())

a = [s] * k
a += [s+1] * (n - k)

print(*a, sep=' ')
