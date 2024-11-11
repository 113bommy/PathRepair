import collections
import math 
N,A,B = map(int, input().split())
x = list(map(int, input().split()))
x.sort()
print(sum(x[-A:])/A)
c = collections.Counter(x)
s=0
ans=0
for i in range(N-1,0,-1):
    t = s
    s+=c.get(x[i])
    if s>=A and t ==0:
        #print(c.get(x[i]))
        for j in range(A,min(c.get(x[i]),B)+1):
            #print(ans)
            ans+=math.factorial(c.get(x[i]))/(math.factorial(c.get(x[i])-j)*math.factorial(j))
        break
    elif s>=A:
        ans+=math.factorial(c.get(x[i]))/math.factorial(c.get(x[i])-(A-t))*math.factorial(A-t)
        break
print(ans)