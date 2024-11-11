import sys

def readstr():
    input = sys.stdin.readline
    a=str(input().split()[0])
    return a

def readnum():
    input = sys.stdin.readline
    a=list(map(int,input().split()))
    return a

def printf(val):
    sys.stdout.write(str(val) + '\n')

def power(a, b, mod):
    if b == 1:
        return a
    if b == 0:
        return 1

    ans = power(a, b//2, mod)
    ans *= ans

    if b % 2:
        ans *= a
    
    ans = ans % mod
    return ans


def factorial(n, start=1, skip=None):
    res = start
    for i in range(1, n+1):
        if i == skip:
            continue
        res *= i
#        res = res % mod

    return res

def make_deg(l):
    deg = {}
    for i in l:
        if not i in deg:
            deg[i] = 0
        deg[i] += 1
    return deg

for _ in range(readnum()[0]):
    n = readnum()[0]
    b = readnum()

    if (2*sum(b)) % (n*(n+1)):
        print ("NO")
        continue

    s = 2*sum(b)//n//(n+1)
   
    a = []
    for i in range(n):
        val = s - b[i] + b[(i-1)%n]
        if val % n != 0 or val == 0:
            a = []
            print ("NO")
            break

        a.append(str(val//n))

    if len(a) > 0:
        print ("YES")
        print (" ".join(a))
        
