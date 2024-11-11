f=lambda:map(int,input().split())
n,k=f()
t=0
for i in range(1,n+1):
    t+=5*i
    if t>240-k:
        break
print(i-1 if i<n else i)