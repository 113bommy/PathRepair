#!/usr/bin/env python
# coding: utf-8

# In[5]:


n=int(input())
output=[]
for i in range(n):
    x=int(input())
    if 360%(360-x)==0:
        output.append('yes')
    else:
        output.append('no')
for k in output:
    print(k)
    


# In[ ]:




