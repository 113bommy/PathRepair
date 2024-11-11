import math
a,b=map(int,input().split())
sum=a*(a+1)//2
candies=0
i=a
y=sum-b
x=(2*a+3)-math.sqrt((2*a+3)**2-8*y)
x=x//2
print(x)

