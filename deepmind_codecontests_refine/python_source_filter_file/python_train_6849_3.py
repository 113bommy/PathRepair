#!/usr/bin/env python
# coding: utf-8

# In[1]:


H,W,K = map(int, input().split())
s = []
for _ in range(H):
    s.append(input())


# In[29]:


ans = [[0]*W for _ in range(H)]
num = 1
for h in range(H):
    if "#" not in s[h]:
        if h != 0:
            ans[h] = ans[h-1]
            continue
        else:
            continue
    is_first = True
    for w in range(W):
        if s[h][w] == "#":
            if is_first:
                is_first = False
            else:
                num += 1
        ans[h][w] = num
    num += 1
for h in range(H-2,-1,-1):
    if 0 in ans[h]:
        ans[h] = ans[h-1]
for h in range(H):
    print(*ans[h])


# In[ ]:




