f=lambda:map(int,input().split())
n,k=f()
t=0
for i in range(1,n+1):
    t+=i*5
    if t>240-k:
        break
print(i-1 if t>240-k else i)