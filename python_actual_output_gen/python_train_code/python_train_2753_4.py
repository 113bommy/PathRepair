def find_inverse(q, n):
    p = [0] * (len(q) + 1)
    p[0], i = 0, 0
    while i < len(q):
        p[i + 1] = q[i] + p[i]
        i += 1
    c = 1 - min(p)
    z = [x + c for x in p]
    if set(z) != set(range(n)):
        return [-1]
    return z


n = int(input())
a = [int(j) for j in input().split()]
print(*find_inverse(a, n))
