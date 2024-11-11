r = 0
p = None
for c in input():
    if p:
        p = None
        r += 1
    elif c == p:
        p = '*'
    else:
        r += 1
        p = c
print(r)
