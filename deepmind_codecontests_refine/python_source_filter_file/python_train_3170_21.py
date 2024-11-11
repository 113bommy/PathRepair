from collections import *
n=int(input())
l=[]
for i in range(n):
    l.append(input())
c=Counter(l)
x=list(c.keys())
y=list(c.values())
d=[]
for i in range(len(x)):
    d.append([y[i],x[i]])
l.sort(reverse=True)
print(d[0][1])
