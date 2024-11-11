n, pos, l, r = map(int, input().split())
total = 0
if pos >= l and pos <= r:
    if pos-l <= r-pos:
        if l != 1:
            total += (pos-l+1)
            if r != n:
                total += (r-l+1)
        else:
            if r != n:
                total += (r-pos)
    else:
        if r != n:
            total += (r-pos+1)
            if l != 1:
                total += (r-l+1)
        else:
            if l != 1:
                total += (pos-l)
else:
    if pos < l:
        total += (l-pos+1)
        if r != n:
            total += (r-l+1)
    else:
        total += (pos-r+1)
        if l != 1:
            total += (r-l+1)

print(total)
