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

def check(a , b):
    n = len(a)
    m = len(b)

    for i in range(m-n):
        if b[i:i+n] == a:
            flag = 1
            for j in range(i):
                if b[j] == '0':
                    flag = 0
            for j in range(i + n, m):
                if b[j] == '0':
                    flag = 0
            if flag:
                return 1
    return 0

x , y = li()

if x == y:
    print("YES")
    exit(0)

if y % 2 == 0:
    print("NO")
    exit(0)

xx = list(bin(x))[2:]
yy = list(bin(y))[2:]
# print(xx , yy)
zz = xx[:]
while zz[-1] == '0':
    zz.pop()
ans = max(check(xx , yy) , check(zz , yy) , check(list(reversed(xx)) , yy),check(list(reversed(zz)) , yy))
# print(ans)
if ans:
    print("YES")
else:
    print("NO")
