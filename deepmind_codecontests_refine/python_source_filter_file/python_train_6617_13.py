#!/usr/bin/env python
# -*- coding: utf-8 -*-

n,n1,n2=map(int,input().split())
ast=input().split()
a=[]
for v in ast:
    a.append(int(v))
a.sort(reverse=True)

if n1>=n2:
    #пихаем самых жирных в n1
    s1=a[0:n1]
    s2=a[n1:(n1+n2)]
    sum1=sum(s1)
    sum2=sum(s2)
    aver=sum1/n1 + sum2/n2
else:
    #пихаем самых жирных в n2
    s1=a[0:n2]
    s2=a[n2:(n1+n2)]
    sum1=sum(s1)
    sum2=sum(s2)
    aver=sum1/n2 + sum2/n1
print(aver)
    



