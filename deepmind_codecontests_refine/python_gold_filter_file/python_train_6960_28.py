W, H, N = map(int,input().split())
#白い領域の端
l = 0
r = W
u = H
d = 0
for i in range(N):
    x, y, a = map(int,input().split())
    if a == 1:
        l = max(x,l)
    elif a == 2:
        r = min(x,r)
    elif a == 3:
        d = max(y,d)
    else:
        u = min(y,u)
print(max((r-l),0)*max((u-d),0))