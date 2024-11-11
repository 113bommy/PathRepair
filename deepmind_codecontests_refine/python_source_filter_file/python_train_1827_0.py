n,m=map(int,input().split())
c2=2*n+1
c1=1
for i in range(m+1):
    if(c2<=m):
        print(c2,end=' ')
        c2+=1
    if(c1<=m):
        print(c1,end=' ')
        c1+=1
print('')
