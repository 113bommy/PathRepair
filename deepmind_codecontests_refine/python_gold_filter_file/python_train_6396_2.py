n, k, x = input().split()
t = input().split() + ['a', 'b']
u, q = -2, 1
for v in range(int(n) + 1):
    if x == t[v]:
        if u == -2: u = v - 1
    elif u != -2:
        s, i, j, y = 0, u, v, t[v]
        while j - i - s > 2:
            s = j - i
            while t[i] == y: i -= 1
            while t[j] == y: j += 1
            y = t[j]
        u, q = -2, max(q, s)
print(q - 1)