H, W, D=map(int, input().split())
pos={}
for i in range(H):
    A=list(map(int, input().split()))
    for j in range(W):
        pos[A[j]]=(i, j)
p=[0]*(H*W+1)
for i in range(D+1,H*W+1):
    p[i]=p[i-D]+abs(pos[i][0]-pos[i-D][0])+abs(pos[i][1]-pos[i-D][1])
Q=int(input())
for _ in range(Q):
    L, R=map(int, input().split())
    print(p[R]-p[L])
