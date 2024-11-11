import math
a,b,c=map(int,input().split())
s1= math.sqrt((a*b)//c)
s2= math.sqrt((c*b)//a)
s3= math.sqrt((a*c)//b)
print(int(4*(s1+s2+s3)))