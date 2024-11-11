n,k=map(int,input().split())
l=list(map(int,input().split()))
c=1
m=0
for i in range(1,n):
    if(l[i]==l[i-1]):
        c=1
    else:
        c+=1
        m=max(m,c)
print(m)
