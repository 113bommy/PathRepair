__author__ = 'Utena'
import math
n,a,b=map(int,input().split())
m=[]
s=[]
for i in range(n):
    m.append(list(map(int,input().split())))
for i in range(n):
    a1,b1=m[i]
    s.append((a1-a)**2+(b1-b)**2)
for i in range(n-1):
    a1,b1=m[i]
    a2,b2=m[i+1]
    if ((a2-a1)*(a2-a)+(b2-b1)*(b2-b))*((a2-a1)*(a1-a)+(b2-b1)*(b1-b))<=0:
        l=((b2-b1)*a-(a2-a1)*b-a1*b2+a2*b1)**2/((b2-b1)**2+(a2-a1)**2)
        s.append(l)
a1,b1=m[-1]
a2,b2=m[1]
if ((a2-a1)*(a2-a)+(b2-b1)*(b2-b))*((a2-a1)*(a1-a)+(b2-b1)*(b1-b))<=0:
    l=((b2-b1)*a-(a2-a1)*b-a1*b2+a2*b1)**2/((b2-b1)**2+(a2-a1)**2)
    s.append(l)
t=math.pi*(max(s)-min(s))
print(t)