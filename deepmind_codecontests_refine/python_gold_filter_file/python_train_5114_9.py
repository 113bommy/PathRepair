n=int(input())
l=list(map(int,input().split()))
c=0
for i in range(1,n-1):
    if(l[i]==0 and l[i-1]==1 and l[i+1]==1):
        c=c+1
        l[i-1]=0
        l[i+1]=0
print(c)