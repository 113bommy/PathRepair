n = int(input())
s = k = 0
for i, x in enumerate(input(), 1):
    if x == 'R': k = i - 1
    elif x == 'L':
        if k: s += (k - i) % 2
        else: s = 0
        k = 0
    elif not k: s += 1
print(s)