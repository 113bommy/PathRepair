n,k=map(int,input().split())
ans = 0
for i in range (0,n):
    q = {int(x) for x in input()}
    if set(range(0,k+1))<=q:
        ans+=1
print (ans)
