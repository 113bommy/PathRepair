input()
s = t = 0
for q in input():
    if q == 'x': s += 1
    else: s, t = 0, t + max(s - 2, 0)
print(t)