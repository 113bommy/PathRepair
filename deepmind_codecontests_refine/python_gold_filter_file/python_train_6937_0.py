n, pos, l, r = [int(x) for x in input().split()]
t = 0
lm = 0
rm = 0
if l > 1:
    t += 1
    lm = abs(pos - l)

if r < n:
    t += 1
    rm = abs(r - pos)
    if lm > 0:
        xm = r - l
        t += xm + min(rm, lm)
    else:
        t += rm
else:
    if lm > 0:
        t += lm

print(t)
