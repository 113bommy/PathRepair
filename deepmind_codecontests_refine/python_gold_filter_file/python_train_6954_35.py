# 2019/12/27

h,w=map(int,input().split())
s=[list('#'*(w+2))]
for _ in range(h):
    s+=[list('#'+input()+'#')]
s+=[list('#'*(w+2))]

L,U,R,D=[[[0]*(w+2) for _ in range(h+2)] for _ in range(4)]

for i in range(1,h+1):
    for j in range(1,w+1):
        if s[i][j]=="#":continue
        L[i][j]=L[i][j-1]+1
        U[i][j]=U[i-1][j]+1

ans=0

for i in range(h,0,-1):
    for j in range(w,0,-1):
        if s[i][j]=="#":continue
        R[i][j]=R[i][j+1]+1
        D[i][j]=D[i+1][j]+1
        lit=L[i][j]+U[i][j]+R[i][j]+D[i][j]-3
        ans=max(ans,lit)
print(ans)