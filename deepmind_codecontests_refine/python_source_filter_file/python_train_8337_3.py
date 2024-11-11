
# coding: utf-8

# In[18]:


a = input().split()
n = int(a[0])
k = int(a[1])
t = input()
for i in range(n) :
    if t[:i] == t[n-i:] :
        f = i
print(t,end='')
for j in range(int(k)) :
    print(t[f:], end='')


# #### 
