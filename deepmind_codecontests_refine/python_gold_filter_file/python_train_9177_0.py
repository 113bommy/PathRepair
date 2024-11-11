n=int(input())
a=list(map(int,input().split()))
for i in range(n):
    if(a[i]>=0):
        a[i]=-a[i]-1
x=a.index(min(a))
if(n%2 and a[x]!=0):
    a[x]=-(a[x]+1)
print(*a)