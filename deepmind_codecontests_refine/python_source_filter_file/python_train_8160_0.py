import math

def lcm(a,b):
    return a*b// math.gcd(a,b)


def egcd(a,b):
    if b==0: return (a, 1, 0)
    g,x,y = egcd(b,a%b)
    return (g, y, x - (a//b) * y)


def crt(a,m1,b,m2):
    g,x,y = egcd(m1,m2)
    if (b-a)%g!=0: return (0,-1)
    m = m1 * m2 // g
    r = (b-a) // g * x % (m2//g)
    r = (a + m1 * r) % m
    return (r, m) 

def nel():
    print("NO")
    exit(0)


x,y,n = map(int,input().split())

v = list(map(int,input().split()))


mn = 1
for i in v: 
    mn = lcm(mn,i)
    if mn > x: nel()

aux = (0, 1)
for i in range(0,n):
    aux = crt(aux[0],aux[1],(-i % v[i] + v[i])%v[i], v[i])
    if aux[1]==-1: nel()

if aux[0]==0: aux = (aux[1],aux[1])

if aux[0]+n>=y: nel()

for i,j in enumerate(v,0):
    res = math.gcd(aux[0]+i,aux[1])
    if res!=j: nel()
print("YES")


