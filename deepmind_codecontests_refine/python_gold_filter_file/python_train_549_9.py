vp = int(input())
vd = int(input())
t = int(input())
f = int(input())
c = int(input())
currentD = 0
ans = 0

if vp >= vd:
    ans = 0
else:
    currentD = vp * t
    
    while currentD < c:
        currentD += (vp * currentD) / (vd - vp)

        if currentD >= c:
            break
        
        ans += 1
        currentD += (f + currentD / vd) * vp

print(ans)
        
