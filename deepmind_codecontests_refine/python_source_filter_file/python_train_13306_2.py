import math
l=int(input())
n=int(math.log2(l)+1)
E=[]
for i in range(n-1):
    E.append([i+1,i+2,0])
    E.append([i+1,i+2,2**i])
i=n-2
while l>2**(n-1):
    t=l-2**i
    if t>2**(n-1)-1:
        E.append([i+1,n,t])
        l=t-1
    i-=1
print(n,len(E))
for i in range(len(E)):
    print(*E[i])