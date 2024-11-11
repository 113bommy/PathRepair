def power(x, y) :
    p = int(1e9 + 7)
    res = 1
    x = x % p  
    while (y > 0) : 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
        y = y >> 1      # y = y/2 
        x = (x * x) % p 
    return res 
n, m = list(map(int, input().strip().split()))
ans = int( power((power(2,m) -1),n))
print(ans)