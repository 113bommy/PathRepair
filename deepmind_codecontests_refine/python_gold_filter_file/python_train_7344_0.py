n,m,l=map(int,input().split())
a=list(map(int,input().split()))
c=0
sum=0
for i in a:
    if i<=m:
        sum=sum+i
    if sum>l:
        sum=0
        c=c+1
print(c)