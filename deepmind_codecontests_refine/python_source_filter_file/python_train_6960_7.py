W, H, N  = map(int,input().split()) 
l = 0; r = W; u = H; d = 0 

for i in range(N):
    x, y, a = map(int,input().split()) 
    if a == 1:
        l = max(l,x) 
    elif a == 2:
        r = min(r,x) 
    elif a == 3:
        d = max(d,y) 
    else:
        u = min(u,y) 

print(max(0,(r-l)*(u-d))) 