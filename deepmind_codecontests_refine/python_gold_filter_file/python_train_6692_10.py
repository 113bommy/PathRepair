#!/usr/bin/env python
# coding: utf-8

# In[ ]:


t=int(input())
for i in range(t) :
    x=input()
    y=int(x[0])
    a=int(len(x))
    n=a*(a+1)/2
    z=int((y-1)*10+n)
    print(z)

