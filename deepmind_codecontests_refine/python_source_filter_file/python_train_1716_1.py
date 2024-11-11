import math
c,hr,hb,wr,wb = map(int,input().split())
if wr < wb:
    wr, wb = wb, wr
    hr, hb = hb, hr
ans = 0
if wr * wr >= c:
    for i in range(int(c/wr)):
        ans = max(ans, i*hr+(c-i*wr)//wb*hb)
else:
    if hr*wb < hb*wr:
        wr, wb = wb, wr
        hr, hb = hb, hr
    for i in range (wr):
        ans = max(ans, i*hb+(c-i*wb)//wr*hr)
print(ans)
        

