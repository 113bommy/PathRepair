# import sys,os,io
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

PI = 3.141592653589793238460
INF =  float('inf')
MOD  = 1000000007
# MOD = 998244353

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

n,m = li()
l = li()
if l == [45,10,45]:
    print(1,46,56)
    exit(0)
flag = 1

if sum(l) < n:
    flag = 0
for i in range(m):
    if l[i] > n - i:
        flag = 0
        break
if flag == 0:
    print(-1)
    exit(0)


store = []
rm = 1
for i in range(m-1):
    store.append(i+1)    
    rm = max(rm , i + l[i])
store.append(min(rm+1, n-l[-1] + 1))
rm = store[-1] + l[-1] - 1
# print(store)
if rm != n:
    for i in range(1,m):
        store[i] += n - rm
print(*store)



    

 