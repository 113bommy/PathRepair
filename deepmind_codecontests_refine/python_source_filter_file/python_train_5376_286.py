import math
n,m=int(input()),int(input())
l=math.log(m,2)
l=math.ceil(l)
if(n<l):
    print(m%(2**n))
else:
    print(m)



