# -*- coding: utf-8 -*-
"""
Created on Wed Mar  1 13:33:38 2017

@author: kyle
"""

a,b = map(int,input().split())
p1 = list(map(int,input().split()))
p2 = list(map(int,input().split()))
3

delta = [(p1[i]-p2[i],i) for i in range(a)]
delta.sort()
#print(delta)

ll=len([i for i in delta if i[0]<=0])
b = max(ll,b)
l1 = [delta[i][1] for i in range(b)]
l2 = [delta[i][1] for i in range(b,a)]
      
m=[p1[i] for i in l1]
n=[p2[i] for i in l2]

print(sum(m+n))