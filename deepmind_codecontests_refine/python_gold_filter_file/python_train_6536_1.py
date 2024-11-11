from sys import stdout
printn = lambda x: stdout.write(str(x))
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 999999999
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

def modinv2(x,r):
  return pow(x,r-2,r)

def f(r,c):
    d = c
    prod = 1
    div = 1
    divacc = 1
    for i in range(r-1):
        prod = (prod*d)%R
        divacc = (divacc*div)%R
        d += 1
        div += 1
    ret = (prod*modinv2(divacc,R))%R
    #ddprint("f r {} c {} ret {}".format(r,c,ret))
    return ret

r1,c1,r2,c2 = inm()
r1 += 1
c1 += 1
r2 += 1
c2 += 1
print((f(r2+1,c2+1)-f(r2+1,c1)-f(r1,c2+1)+f(r1,c1))%R)
