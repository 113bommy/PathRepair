from collections import deque
def ints():
    return map(int,input().split())
n,k=ints()
sieve=[True for i in range(n+1)]
for i in range(2,int(n**(1/2))+1):
    if sieve[i]:
        for j in range(i*i,n+1,i):
            sieve[j]=False

count=[0 for i in range(n+1)]
c=0
curr=2
for i in range(3,n+1):
    if sieve[i]:
        if curr+i+1<=n and sieve[curr+i+1]:
            count[curr+i+1]=1
        curr=i

fin=[0]
for e in count:
    if e==1:
        fin.append(fin[-1]+1)
    else:
        fin.append(fin[-1])

if fin[n]>=k:
    print("YES")
else:
    print("NO")
        
    

