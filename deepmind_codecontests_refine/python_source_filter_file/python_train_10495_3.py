import sys

sys.setrecursionlimit(100000)


H,W=map(int,input().split())
S=[]
for i in range(H):
    S.append(input())

def DFS(h,w,black,white,m):
    black,white=BorW(h,w,black,white)
    step=[[0,1],[0,-1],[1,0],[-1,0]]
    seen[h][w]=1
    for dh,dw in step:
        nh=h+dh
        nw=w+dw
        if 0<=nh<H and 0<=nw<W:
            if seen[nh][nw]==0 and m!=S[nh][nw]:
                seen[nh][nw]=1
                black,white=DFS(nh,nw,black,white,S[nh][nw])
    return black,white


def BorW(h,w,black,white):
    if S[h][w]=="#":
        black+=1
    else:
        white+=1
    return black,white


seen=[[0]*W for _ in range(H)]

L=[]
for h in range(H):
    for w in range(W):
        black=0
        white=0
        if seen[h][w]==0:
            black,white=DFS(h,w,black,white,S[h][w])
            L.append([black,white])
ans=0
for b,w in L:
     ans+=b*w

print(ans)