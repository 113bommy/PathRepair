from itertools import product

x, y, z, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

p = [i + k for i, k in product(a, b)]
p.sort(reverse=True)
q = [i + k for i, k in product(p[:k], c)]
q.sort(reverse=True)

print('\n'.join(map(str, q[:k])))
