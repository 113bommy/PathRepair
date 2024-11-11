from collections import defaultdict
def factorize(n):
    d=defaultdict(int)
    count = 0 
    while ((n % 2 > 0) == False):  
        n >>= 1  
        count += 1
    if (count > 0): 
        d[2]+=count 
    for i in range(3, int(n**0.5) + 1): 
        count = 0
        while (n % i == 0):  
            count += 1
            n//=i
        if (count > 0): 
            d[i]+=count 
        i += 2  
    if (n > 2): 
        d[n]+=1
    return d
for i in range(int(input())):
    p,q=map(int,input().split())
    d2=factorize(q)
    ans=1
    for j in d2:
        c=j**d2[j]
        if p%c:
            ans=p
            break
        a=p//c
        if a%j==0:
            a//=j
        ans=max(ans,a)
    print(ans)
