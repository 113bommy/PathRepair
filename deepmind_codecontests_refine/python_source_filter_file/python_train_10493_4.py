import math
a,b,x = map(int,input().split())
s = x / a
print(s)
if s > b*a/2:
    print(math.degrees(math.atan(2*(a*b-s)/(a*a))))
else:
    print(math.degrees(math.atan(b*b/(2*s))))