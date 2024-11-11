w,h,n = map(int,input().split())
ww=hh=0
for _ in [0]*n:
    x,y,a = map(int,input().split())
    if a == 1:
        ww = max(ww,x)
    elif a == 2:
        w = min(w,x)
    elif a == 3:
        hh = max(hh,y)
    else:
        h = min(h,y)
print((w-ww)*(h-hh)*(w>ww)*(h>hh))