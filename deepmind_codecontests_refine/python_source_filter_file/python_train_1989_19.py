import math
n=int(input())
m=int(input())
y=[]
for _ in range(n):
    x=int(input())
    y.append(x)
max_=max(y)
summ=0
for i in range(n):
    summ+=max_ - y[i]
kmax=max_+m

kmin=0
if summ<=m and summ!=0:
    kmin=max_
else:
    kmin=max_ + math.ceil((m-summ)/n)

print(kmin,'',kmax)


