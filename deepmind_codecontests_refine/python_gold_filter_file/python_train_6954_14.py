H,W=map(int, input().split())
S=[input() for i in range(H)]
l=[[0]*W for i in range(H)]
r=[[0]*W for i in range(H)]
t=[[0]*W for i in range(H)]
b=[[0]*W for i in range(H)]
for h in range(H):
    for w in range(W):
        if S[h][w]=='.':
            l[h][w]=l[h][w-1]+1
            t[h][w]=t[h-1][w]+1
        if S[h][W-w-1]=='.':
            r[h][W-w-1]=r[h][-w]+1
        if S[H-h-1][w]=='.':
            b[H-h-1][w]=b[-h][w]+1
ans=0
for h in range(H):
    for w in range(W):
        ans=max(ans,l[h][w]+r[h][w]+t[h][w]+b[h][w]-3)
print(ans)