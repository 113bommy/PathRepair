N,X,Y=map(int,input().split())
l=[0]*N
for i in range(1,N):
    for j in range(i):
        l[min(abs(i-j-1),abs(X-j-1)+abs(Y-i-1))]+=1
print(*l,sep="\n")