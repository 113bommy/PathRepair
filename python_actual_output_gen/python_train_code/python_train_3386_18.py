n,x=map(int,input().split())
k=0
ind=0
for i in range(n):
    l,r=map(int,input().split())
    ind+=(l-ind)/x*x
    k+=r-ind+1
    ind=r+1
print(k)
