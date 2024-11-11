#!/usr/bin/env python
# coding: utf-8

# In[21]:


def lis(arr):
    stack = [arr[0]]
    for i in range(1,len(arr)):
        if arr[i] not in stack:
            stack.append(arr[i])
    return stack
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int,input().split()))
    print(*lis(arr))


# In[ ]:




