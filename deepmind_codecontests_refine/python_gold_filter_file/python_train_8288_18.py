t, a, b = input(), input(), input()
k, l = 0, len(a) - 1
i, j = t.find(a), t.rfind(b)
if i > -1 and j > -1 and i + l < j: k += 1
t = t[:: -1]
i, j = t.find(a), t.rfind(b)
if i > -1 and j > -1 and i + l < j: k += 2
print(['fantasy', 'forward', 'backward', 'both'][k])