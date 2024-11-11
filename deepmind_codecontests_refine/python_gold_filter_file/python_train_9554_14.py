h,w,m = map(int,input().split())

tate = [0]*(h+1)
yoko = [0]*(w+1)

basyo = []

for i in range(m):
    hh,ww = map(int,input().split())
    basyo.append((hh-1,ww-1))
    
    tate[hh-1] += 1
    yoko[ww-1] += 1
    
tt,yy = 0,0
x = max(tate)

for i in tate:
    if i == x:
        tt += 1
        
y = max(yoko)
for i in yoko:
    if i == y:
        yy += 1
        
ans = x+y
pl = tt * yy

cur = 0
for i,j in basyo:
    if tate[i] + yoko[j] == ans:
        cur += 1
        
if pl > cur:
    print(ans)
else:
    print(ans-1)