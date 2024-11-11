import sys
def input():
    return sys.stdin.readline().strip()
 
 
def iinput():
    return int(input())
 
 
def tinput():
    return input().split()
 
 
def rinput():
    return map(int, tinput())
 
 
def rlinput():
    return list(rinput())

def gcd(a,b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)

p,q = rinput()
P = rlinput()
Q = rlinput()
if p < q:
    print("0/1")
elif p == q:
    hcf = gcd(P[0],Q[0])
    num = P[0] // hcf
    den = Q[0] // hcf
    print(f"{num}/{den}")
else:
    if (P[0] > 0 and Q[0] > 0) or (P[0] > 0 and Q[0] > 0):
        print("Infinity")
    else:
        print("-Infinity")