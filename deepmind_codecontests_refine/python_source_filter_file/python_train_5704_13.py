h,w=map(int,input().split())
S=[]
for i in range(h):
    S.append(input())

cnt=0
D=[[10**9]*w for _ in range(h)]
D[0][0]=0
for i in range(h):
    for j in range(w):
        if j>0:
            D[i][j]=D[i][j-1]+(S[i][j]!=S[i][j-1])
        if i>0:
            D[i][j]=min(D[i][j],D[i-1][j]+(S[i][j]!=S[i-1][j]))   
                
                
if S[0][0]=='#':
    print(1+D[h-1][w-1]//2)
else:
    print((D[h-1][w-1]+1)//2+(S[0][0]!=S[h-1][w-1]))