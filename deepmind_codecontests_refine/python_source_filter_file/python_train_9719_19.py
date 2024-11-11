import math
s1,s2,s3=map(int,input().rstrip().split())
a=math.sqrt((s1*s3)/s2)
b=math.sqrt((s1*s2)/s3)
c=math.sqrt((s2*s3)/s1)
print(4*(a+b+c))