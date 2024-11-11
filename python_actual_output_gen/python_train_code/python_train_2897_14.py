import sys
def inpt():
   return sys.stdin.readline().strip()
x=[int(i) for i in inpt().split()]
m=min(x)
if  m==x[0]:
     print(3*m-3)
elif m==x[1]:
    if m+1>x[2]:
        m-=1
    print(3*m)
elif m==x[0]:
    if m+1>x[1]:
        m-=1
    if m+2>x[2]:
        m-=1
    print(3*m+3) 