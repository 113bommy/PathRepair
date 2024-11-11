n,m = map(int, input().split(" "))
res = 1

def power(x, y, p) : 
    res = 1
    x = x % p  
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
        y = y >> 1
        x = (x * x) % p 
    return res
    
res = power(2,m,1000000007)
if res == 0:
    res = 1000000007 - 1
else:
    res = res - 1
res1 = power(res,n,100000007)
print(res1)