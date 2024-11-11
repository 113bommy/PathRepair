import math

a ,b ,c = [int(x) for x in (input().split())]

s1=math.sqrt((a*b)/c)
s2=math.sqrt((a*c)/b)
s3=math.sqrt((c*b)/a)

s=s1+s2+s3
print (s)
