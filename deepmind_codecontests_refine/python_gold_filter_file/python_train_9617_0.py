n = int(input())
a, b = [0] * (n + 2), [0] * (n + 2)
s, l = 0, 1
p = [0] * n
for i in range(n):
    t = list(map(int, input().split()))
    if t[0] == 1:
        b[t[1] - 1] += t[2]
        s += t[1] * t[2]
    elif t[0] == 2:
        a[l] = t[1]
        l += 1
        s += t[1]
    else:
        l -= 1
        s -= a[l] + b[l]
        b[l - 1] += b[l]
        b[l] = 0
    p[i] = str(s / l)
print('\n'.join(p))