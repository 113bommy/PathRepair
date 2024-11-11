w,h,n = map(int,input().split())
b,c,d,e = 0,w,0,h
for i in range(n):
    x,y,a = map(int,input().split())
    if a == 1:
        b = max(b,x)
    elif a == 2:
        c = min(c,x)
    elif a == 3:
        d = max(d.y)
    else:
        e = min(e,y)
print(max(c-b,0)*max(e-d,0))