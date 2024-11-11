n = int(input())
vals = list(map(int, input().split()))
pref, suff = [0] * (n + 1), [0] * (n + 1)
for i in range(n):
    pref[i + 1] = pref[i] | vals[i]
    suff[n - i - 1] = suff[n - i] | vals[n - i - 1]
ret = (-float('inf'), -float('inf'))
for i, a in enumerate(vals):
    b = pref[i] | suff[i + 1]
    ret = max(ret, (a ^ (a & b), i))
print([vals[ret[1]]] + [v for i, v in enumerate(vals) if i != ret[1]])