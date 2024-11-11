H,W=map(int,input().split())
L=[[0 for i in range(W)]for j in range(H)]
for i in range (H):
  L[i]=list(input())

for a in range(H):
    for b in range(W):
        if L[a][b]=='.':
             num=0
             for k in range(-1,2):
                 for l in range(-1,2):
                    if 0<=a+k<=H-1 and 0<=b+l<=W-1 and L[a+k][b+l]=='#':
                        num+=1
             L[a][b]=num
    print(*L[a])