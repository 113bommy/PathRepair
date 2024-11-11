# import sys,os,io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

PI = 3.141592653589793238460
INF =  float('inf')
MOD  = 1000000007
# MOD = 998244353


def bin32(num):
    return '{0:032b}'.format(num)

def add(x,y):
    return (x+y)%MOD

def sub(x,y):
    return (x-y+MOD)%MOD

def mul(x,y):
    return (x*y)%MOD

def gcd(x,y):
    if y == 0:
        return x
    return gcd(y,x%y)

def lcm(x,y):
    return (x*y)//gcd(x,y)

def power(x,y):
    res = 1
    x%=MOD
    while y!=0:
        if y&1 :
            res = mul(res,x)
        y>>=1
        x = mul(x,x)
        
    return res
        
def mod_inv(n):
    return power(n,MOD-2)

def prob(p,q):
    return mul(p,power(q,MOD-2))    
  
def ii():
    return int(input())

def li():
    return [int(i) for i in input().split()]

def ls():
    return [i for i in input().split()]



for t in range(ii()):
    t+=1
    n = ii()
    a = li()
    if n == 1:
        print(1)
        continue
    elif n == 2:
        print(3)
        continue
    
    ans = 0
    for i in range(n-3):
        x = a[i:i+4][:]
        maxi = 4
        if x[0] <= x[1] <= x[2] or x[0] >= x[1] >= x[2]:
            maxi = 2
        elif  x[0] <= x[2] <= x[3] or x[0] >= x[2] >= x[3] or x[1] >= x[2] >= x[3] or x[1] <= x[2] <= x[3] or x[0] <= x[1] <= x[3] or x[0] >= x[1] >= x[3] :
            maxi = 3

        else:
            maxi = 4
        print(i, maxi , x)
        ans += maxi
    # print(ans)
    if a[n-3] <= a[n-2] <=a[n-1] or a[n-3] >= a[n-2] >=a[n-1]:
        ans += 2
    else:
        ans +=3
    ans += 3
    print(ans )

    


  