import math
def check(arr, a, b):
    d = []
    ll = a*b//math.gcd(a, b)
    for i in range(1, ll+1):
        if i%a%b != i%b%a:
            d.append(1)
        else:
            d.append(0)
   
    
    for i in range(1, len(d)):
        if d[i] == 1:
            d[i] = d[i-1] + 1
        else:
            d[i] = d[i-1]
    
    
    result = []
    last = d[-1]
    for l, r in arr:
        p = 1
        q = 1
        
        kk = last*(r//ll) - last*(l//ll)
       
        l -= 1
        r = r % ll
        if r == 0:
            p = 0
        else:
            r -= 1
        l = l % ll
        if l == 0:
            q = 0
        else:
            l -= 1
        
        result.append(p*d[r] - q*d[l] + kk)
    return result
            
        
    
    
            
    
t = int(input())
while t:
    a, b, q = list(map(int, input().split()))
    arr = []
    for i in range(q):
        arr.append(list(map(int, input().split())))
    result = check(arr, a, b)
    for i in result:
        print(i, end=" " )
    print()
        
    
   

    t-= 1
