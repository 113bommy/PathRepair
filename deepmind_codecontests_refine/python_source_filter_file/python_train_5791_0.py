h = [(i, j) for i in range(9) for j in range(i + 1, 9)]
n = int(input())
s, p = {}, [''] * n
for k in range(n):
    t = input()
    for q in [t[i: j] for i, j in h]: 
        s[q] = -1 if q in s and s[q] - k else k
for q, k in s.items():
    if k >= 0:
        if p[k]:
            if len(p[k]) > len(q): p[k] = q
        else:
            p[k] = q
print('\n'.join(p))