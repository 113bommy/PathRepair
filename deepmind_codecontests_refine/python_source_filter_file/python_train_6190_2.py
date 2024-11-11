n, p = map(int, input().split())

def f(t, k):
    a, b = min(t[k - 1], 2), min(t[k], 2)
    if a == b: a = 1
    return [3 - a - b, a, b]

def g(t, k):
    j = t[k]
    for i in range(j + 1, p):
        if i != t[k - 1] and i != t[k - 2]:
            t[k] = i
            return f(t, k)
    return None

def h(t):
    t = [ord(c) - 97 for c in t] + [2, 2]
    for k in range(n - 1, -1, -1):
        s = g(t, k)
        if s:
            d = n - k - 1
            t = t[: k + 1] + s * (d // 3) + s[: d % 3]
            return ''.join(chr(i + 97) for i in t)
    return 'NO'

t = input()
q = 'NO'
if p == 2:
    if t == 'a': q = 'b'
    elif t == 'ab': q = 'ba'
elif p > 2: q = h(t)
print(q)