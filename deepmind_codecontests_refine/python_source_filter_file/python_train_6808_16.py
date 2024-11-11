#!/usr/bin/env python
# coding: utf-8

# In[41]:


## Inputs
# n = int(input())
code = str(input())

stack = ''
ans = ''

for sym in code:
    stack += sym
    if stack == '.':
        ans += '0'
        stack = ''
    elif stack == '-.':
        ans += '1'
        stack = ''
    elif stack == '--':
        ans += '2'
        stack = ''

print(int(ans))


# In[ ]:




