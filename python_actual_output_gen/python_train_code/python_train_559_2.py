m = list(map(int,input().split(' ')))
a = m[0]
b = m[1]
c = m[2]
ways = 1
def fact(n):
    a = 1
    for i in range(2,n):
        a *= i
    return a
def p(r,n):
    return fact(n)//fact(r)
def entekhab(r,n):
    return p(r,n)//fact(n-r)
ways *= b
a -= 1
ways *= entekhab(c,a)
ways *= (b-1)**c
print(ways%998244353)
