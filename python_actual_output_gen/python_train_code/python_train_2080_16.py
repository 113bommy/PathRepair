h,w = map(int,input().split())
ans = 10**10

def menseki(h,w):
    global ans
    for i in range(1,h):
        # 縦1横2
        haba = w//2
        ans = min(ans,max(i*w,haba*(h-i),(w-haba)*(h-i))-min(i*w,haba*(h-i),(w-haba)*(h-i)))
        # 縦3分割
        if h-i == 1:
            continue
        tate = (h-i)//2
        ans = min(ans,max(w*i,tate*w,(h-tate)*w)-min(w*i,tate*w,(h-tate)*w))

menseki(h,w)
menseki(w,h)

print(ans)