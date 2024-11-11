n,v=list(map(int,input().split()))
a=list(map(int,input().split()))
b=list(map(int,input().split()))
m=1000000 
for i in range(n):
    m=min(m,b[i]/a[i])
c=0 
for i in range(n):
    c+=m*a[i] 
print(min(c,v))