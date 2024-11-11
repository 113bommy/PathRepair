n, pos, l, r = [int(i) for i in input().split()]
if l == 1 and r == n:
    print(0)
elif l == 1:
    if pos > r:
        print(pos - r + 1)
    else:
        print(r - pos + 1)
elif r == n:
    if pos < l:
        print(l - pos + 1)
    else:
        print(pos - l + 1)
else:
    if pos < l:
        print(l - pos + 1 + r - l + 1)
    elif pos > r:
        print(pos - r + 1 + r - l + 1)
    else:
        print(min(pos - l, r - pos) * 2 + max(pos - l, r - pos) + 2)