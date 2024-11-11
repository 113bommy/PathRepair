a = []
for c in input():
    if c in '01':
        a.append(c)
    else:
        a = a[:-1]
print("".join(a))
