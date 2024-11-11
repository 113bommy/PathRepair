def fac1(n):
    fac = 1 
    i = 0 
    while i < n:
         i += 1
         fac = fac * i 
    return fac
def gcd(x,y):
    while y:
        x, y = y, x % y
    return x
def gcdfac(x,y):
    if x > y:
        return fac1(x)
    else: return fac1(y)

x,y = map(int,input().split())
print(gcdfac(x,y))