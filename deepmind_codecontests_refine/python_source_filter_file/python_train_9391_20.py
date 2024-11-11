import math
mas=[]
n=int(input())
for i in range(0,n):
    a,b,c,r=list(map(int,input().split()))
    if b<a: a,b=b,a
    x=b-a
    if c-r==a and c+r==b: x=x-2*(c-a)
    if c-r>a and c+r<b: x=x-(2*r)
    if c-r<=a and c+r>=b: x=x-(b-a) #x=0
    if c-r<=a and c+r<b: x=x-(2*a+b) 
    if c-r>a and c+r>=b: x=x-(b-(c-r))
    if c+r<a and c+r<b: x=b-a 
    if c-r>a and c-r>b: x=b-a
    if r==0: x=b-a
    mas.append(x)
    mas[i]=max(0,mas[i])
for i in range(n): print(mas[i])


