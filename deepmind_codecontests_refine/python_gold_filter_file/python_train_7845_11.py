#!/usr/bin/env python
# coding: utf-8

# In[6]:


n=int(input())
output=[]
for i in range(n):
    x=int(input())
    if 360%(180-x)==0:
        output.append('YES')
    else:
        output.append('NO')
for k in output:
    print(k)
    


# In[ ]:




