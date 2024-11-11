import sys,os,io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

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




n = ii()
a = li()
dp = [ [ -INF for i in range( 62)] for j in range(n) ]

dp[0][a[0] + 30] = 0
ans = 0
for i in range(1 , n):
    x = a[i] + 30
    for j in range(x +1):
        dp[i][x] = max( dp[i][x] , dp[i-1][j] + j - 30 , 0 )
        ans = max(ans , dp[i][j])
    for j in range(x+1 , 62):
        dp[i][j] = max ( dp[i][j] , dp[i-1][j  ] +a[i] )  
        ans = max(ans , dp[i][j])

print(ans)
        




