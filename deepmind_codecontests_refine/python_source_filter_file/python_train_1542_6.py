n=int(input())
a=list(map(int, input().split())) 
b=[0]*n
c=[]
for i in range(1,n+1):
    if sum(b[n-i:n+1:n+1-i])%2==a[n-i]:
        pass
        
    else:
        b[n-i]=1
        c.append(b[n-i])
print(len(c))
print(*c)