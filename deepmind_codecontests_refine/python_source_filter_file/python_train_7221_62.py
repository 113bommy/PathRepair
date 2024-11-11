import math
a=[]
for i in range(5):
    a.append([int(x) for x in input().split()])
for i in range(5):
    for j in range(5):
        if(a[i][j]==1):
            x=int(i)
            y=int(j)
c=abs(3-x)+abs(y-3)
print(c)