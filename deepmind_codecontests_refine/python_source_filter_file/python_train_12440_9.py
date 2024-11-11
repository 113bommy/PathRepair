from sys import stdin as sin , stdout as sout
from math import gcd as g
n = int(sin.readline())
l = list(map(int,sin.readline().split(" ")))
pro = l[0]
for i in range(1,n):
    pro =g(pro,l[i])
print(pro)
for i in range(0,n):
    p = l[i]//pro
    while p%2==0:
        p/=2
    while p%3==0:
        p/=3
    if p!=1:
        sout.write("No")
        sout.flush()
        exit(0)
        break

sout.write("Yes")
sout.flush()

