def f(n):
    m = int(n ** 0.5) + 1
    t = [1] * (n + 1)
    for i in range(3, m):
        if t[i]: t[i * i :: 2 * i] = [0] * ((n - i * i) // (2 * i) + 1)
    return [2] + [i for i in range(3, n, 2) if t[i]]

n, k = map(int, input().split())
s, p = 0, f(n)
t = set(p)
for i in range(1, len(p)):
    if p[i] + p[i - 1] + 1 in t: s += 1
        
print('YNEOS'[s < k :: 2])