# -*- coding: utf-8 -*-

n,vb,vs = map(int, input().split())
a = list(map(float, input().split()))
x,y = map(float,input().split())

dist,index = 10**5,0
for i in range(1,n):
    eucl = (((x-a[i])**2+y**2)**0.5)/vs+a[i]/vb
    if eucl <= dist:
        dist,index = eucl,i
        
print(index+1)
