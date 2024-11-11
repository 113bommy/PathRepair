#!/usr/bin/env python
# coding: utf-8

# In[14]:


n, k=map(int, input().rstrip().split())


# In[15]:


tabs=list(map(int, input().rstrip().split()))


# In[16]:


diff=sum(tabs)
adiff=-1


# In[18]:


for j in range(0,k):
    m=0
    while m*k+j<n:
        diff+=-tabs[m*k+j]
        m+=1
    if abs(diff)>adiff:
        adiff=abs(diff)
        
    diff=sum(tabs)

    
    
print(adiff)    


# In[ ]:




