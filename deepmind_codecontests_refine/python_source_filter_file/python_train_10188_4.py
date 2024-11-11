n = int(input())
p = [int(s) - 1 for s in input().split()]

a = [40_000 * (i + 1) for i in range(n)]
b = list(reversed(a))
for i in range(n):
    a[p[i]] += i

print(' '.join(map(str, a)))
print(' '.join(map(str, b)))