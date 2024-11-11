def primeFactors(n): 
    ans = 0
    while(n%2==0):
        n//=2
        ans+=1
    return ans,n
          
import math
for _ in range(int(input())):
    n = int(input())
    s = set(map(int,input().split()))
    l = list(s)
    # p = 1/max(l)
    if n==1: 
        print(-1)
        continue
    ans = -1
    if max(l)!=0:
        maxV = 2**(math.ceil(math.log(max(l),2)))
        for i in range(1,1024):
            new  = set([])
            for j in l:
                new.add(j^i)
            # print(i,new,s)
            if new==s:
                ans = i
                break
        
    print(ans)
        
