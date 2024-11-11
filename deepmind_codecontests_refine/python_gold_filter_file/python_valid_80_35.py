import sys,os,io
input = sys.stdin.readline # for strings
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline # for non-strings

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
    s = input().strip()

    ind = -1
    for i in range(n-1 , -1,-1):
        if s[i] == '0':
            ind = i
            break
    
    if ind == -1:
        if n % 2:
            print(1 , (n+1)//2 , (n+1)//2  , n )
        else:
            print(1 , (n+1)//2 , (n+1)//2  + 1 , n )
        continue
    ind +=1
    if n % 2:
            
        if ind >= (n+1)//2:
            print(1 , ind , 1 , ind -1)
            continue
        else:
            print(ind  , n , ind  + 1, n)
        
    else:
        if ind > n//2:
            print(1 , ind , 1 , ind -1 )
            continue
        else:
            print(ind  , n , ind  + 1, n)