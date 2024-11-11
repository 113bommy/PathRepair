x, t, a, b, da, db = map(int, input().split())
A, B = [0] + [a - da * i for i in range(t)], set([0] + [b - db * i for i in range(t)])
print('YES' if all(x - i in B for i in A) else 'NO')