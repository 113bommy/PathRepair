import io,os,sys
##input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

import math
def upper_bound(nums, target):
    l, r = 0, len(nums) - 1
    while l <= r:
        mid = l + (r - l) // 2
        if nums[mid] > target:
            r = mid - 1
        else:
            l = mid + 1
    return l

def isPrime(n):
    if(n<=1): return 1;
    else:
        i=2;
        while(i*i<=n):
            if(n%i==0): return 0;
            i+=1;
    return 1;

def seive(n):
    a = [1]
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p ** 2,n + 1, p): 
                prime[i] = False
        p = p + 1
    for p in range(2,n + 1): 
        if prime[p]: 
            a.append(p)
    return(a)

primeList = seive(int(1e6+5));
t = int(input())
y = [int(i) for i in input().split()]
#y = list(map(int,input().split()))

#print("done")
r=""
for i in range(t):
    x = y[i]
    xx = math.sqrt(x);
    maxIndex = upper_bound(primeList,x);
    lowIndex = upper_bound(primeList,int(xx));
    r+=str(maxIndex - lowIndex +1) + '\n'
    #sys.stdout.write(str((maxIndex - lowIndex +1)) + "\n")

    
#print(r)    
