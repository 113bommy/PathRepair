W,H = map(int,input().split())
ans = 10**100
for i in range(1,W):
    a = H*i
    w = W - i
    b = min((w//2)*H,w*(H//2))
    c = w*H - b
    x = max(a,b,c) - min(a,b,c)
    ans = min(ans,x)
for i in range(1,H):
    a = W*i
    h = H - i
    b = min((W//2)*h,W*(h//2))
    c = h*W - b
    x = max(a,b,c) - min(a,b,c)
    ans = min(ans,x)
print(ans)