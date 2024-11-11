#!/usr/bin/env python
# coding: utf-8

# In[116]:


sh, sm = map(int, input().split(':'))
eh, em = map(int, input().split(':'))

start = sh * 60 + sm
end = eh * 60 + em

res = (end - start) // 2

print("{:0>2}:{:0>2}".format(res//60, res - res // 60 * 60))

