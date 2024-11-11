vp = int(input())
vd = int(input())
t = int(input())
f = int(input())
c = int(input())
s = t * vp
ans = 0
ch = c - vp * t
while True:
    if vp >= vd:
        break
    dt = s / (vd - vp)
    ch -= dt * vp
    s = 0
    if ch <= 0:
        break
    else:
        ans += 1
        ch -= vp * ((c - ch) / vd + f)
        s = c - ch
print(ans)
    
    
