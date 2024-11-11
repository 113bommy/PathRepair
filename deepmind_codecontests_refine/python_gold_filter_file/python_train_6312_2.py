
# coding: utf-8

# In[36]:


import math

def UnusualSeq(a,b):
    if b%a!=0:
        print(0)
    else:
        b//=a
        d=set()
        for i in range(1,int(math.sqrt(b)+1)):
            if b%i==0:
                d.add(i)
                d.add(b//i)
        d=sorted(list(d))
        f=d[::]
        for i in range(len(f)):
            f[i]=pow(2,d[i]-1,(10**9+7))
            for j in range(i):
                if d[i]%d[j]==0:
                    f[i]-=f[j]
        print(f[-1]%(10**9+7))


a,b=map(int,input().split())
UnusualSeq(a,b)

