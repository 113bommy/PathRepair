n, k, s = map(int, input().split())

a = [s] * k
a += [1] * (n - k)

print(*a, sep=' ')
