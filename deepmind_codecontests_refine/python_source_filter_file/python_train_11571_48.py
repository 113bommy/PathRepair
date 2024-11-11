n,v=map(int,input().split())

if v<n:
    c=v
    for i in range(2,n+1-v):
        c+=i
else:
    c=n
print(c)