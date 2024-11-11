n = int(input())
a = list(reversed([int(input()) for i in range(n+1) ]))

prime = [2,3]

for i in range(5,100000):
    f = True
    for p in prime:
        if(p*p > i):break
        if i % p == 0 :
            f = False
            break
    if f :prime.append(i)

def gcd(x,y):
    if(x < y): x,y = y,x
    if(y == 0): return x
    return gcd(y,x % y)

def isprime(x):
    f = True
    for p in prime:
        if(p*p > x):break
        if x % p == 0:
            f = False
            break
    return f

g = 0
for i in a:
    g = gcd(abs(i),g)



for p in prime:
    if (p > n+1):break
    m = [0 for i in range(p-1)]
    if a[0] % p != 0:continue
    for i in range(n+1):
        m[i % (p-1)] += (a[i] % p)
    f = True
    for i in m:
        if i % p > 0 :
            f = False
            break    
    if f:print(p)




for p in prime:
    if g == 1:break
    if(g % p == 0):
        g //= p
        if (p > n+1):print(p)

if(g != 1):
    if isprime(g):print(g)