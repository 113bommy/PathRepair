import math
a=[]
for i in range(5):
    a.append([int(x) for x in input().split()])
for i in range(5):
    for j in range(5):
        if(a[i][j]==1):
            x=int(i)
            y=int(j)
c=abs(2-x)+abs(y-2)
print(c)