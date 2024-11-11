import math

s = (input().split())

n = int(s[0])
a = int(s[1])
b = int(s[2])
c = int(s[3])

ost = n%4

if ost == 0:
    print(0)

dob = 4 - ost

m = min (a*6,b*3,c*2)

if dob == 3 :
    print(min(3*a,a+b,c))
if dob == 2 :
    print(min(2*a,b,2*c))
if dob == 1 :
    print(min(a,b+c,3*c))





