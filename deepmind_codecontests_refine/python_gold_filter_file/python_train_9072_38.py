import math
a=int(input())
m=math.ceil((a+1)/2)
print(m)
for i in range(1,min(a+1,m+1)):
    print(1,i)
    a=a-1
for i in range(m-a+1,m+1):
    if(a<=0):
        break
    print(m,i)
    a=a-1