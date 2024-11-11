import math
n=int(input())
li=[]
li=input().split()
a=li.count(str(1))
b=li.count(str(2))
c=li.count(str(3))
d=li.count(str(4))
car=d+c+math.ceil(b/2)
if b%2==0:
    if a<=c:
        print(car)
    else:
        print(car+math.ceil((a-c)/4))
if b%2==1:
    if a<=c+2:
        print(car)
    else:
        print(car+math.ceil((a-c)/4))
