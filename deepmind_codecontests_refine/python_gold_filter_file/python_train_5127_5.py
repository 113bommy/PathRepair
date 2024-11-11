#!/usr/bin/env python
# coding: utf-8

# In[ ]:


def f_of(n):
    i=2
    j=1
    if n%2!=0:
        i=3
        j=2
    while True:
        if n%i==0:
            break
        elif i>=n/2:
            i=n
            break
        i+=j
    return i


testcase=int(input())
answer=[]


while testcase!=0:
    n_k=input()
    n_k=n_k.split()
    n=int(n_k[0])
    k=int(n_k[1])
    while k!=0:
        sd=f_of(n)
        if sd==2:
            n=n+(k*2)
            break
        n=sd+n
        k-=1
    answer.append(n)
    testcase-=1
    
    
for i in answer:
    print(i)


# In[ ]:





# In[ ]:




