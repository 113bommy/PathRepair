import math
n,vb,vs = map(int, input().strip().split(' '))
lst = list(map(int, input().strip().split(' ')))
x,y = map(int, input().strip().split(' '))
m=1000000000
t=0
for i in range(1,n):
    k=math.sqrt((y**2)+(x-lst[i])**2)
    p=lst[i]/vb + ((k)/vs)
    if p<m:
        m=p
        t=i+1
    elif p==m:
        if abs(x-lst[i])<abs(x-lst[t-1]):
            m=p
            t=i+1
print(t)
    