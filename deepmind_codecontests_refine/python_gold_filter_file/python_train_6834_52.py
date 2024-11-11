pt = lambda *a, **k: print(*a, **k, flush=True)
k = int(input())
if k > 36:
    pt(-1)
else:
    while k:
        if k & 1:
            pt('4', end='')
            k -= 1
        else:
            pt('8', end='')
            k -= 2
