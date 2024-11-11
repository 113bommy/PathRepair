W,H,N = map(int,input().split())
w=h=0
for _ in[0]*N:
    x,y,a = map(int,input().split())
    if a == 1:
        w = max(w,x)
    elif a == 2:
        W = min(W,x)
    elif a == 3:
        h = max(h,y)
    else:
        H = min(H,y)
print((W-w)*(H-h)*(W>w)*(H>h))