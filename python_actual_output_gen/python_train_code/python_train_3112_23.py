d4, d7 = 0, 0
for ch in input():
    if ch == '4':
        d4 += 1
    elif ch == '7':
        d7 += 1
if d7 > d4:
    print(7)
else:
    print(4 if d4 > 0 else 0)
