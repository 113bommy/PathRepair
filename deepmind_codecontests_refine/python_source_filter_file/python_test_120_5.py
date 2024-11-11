import math
import random
T=int(input())
for t in range(T):
   # arrayz=random.sample(range(1,10000), 2)
    arrayz=[int(i) for i in input().split()]
    l=min(arrayz)
    r=max(arrayz)
    d=dict()
    s=1
    dig=[]
    for i in range(30):
        dig.append(s)
        s*=2
    mul=2
    for i in range(len(dig)):
        start=dig[i]
        if start>r:
            break
        m1=(l-start)/mul
        m1=math.ceil(m1)
        first=m1*mul+start
        if first<=r:
            sets=((r-first+1)//mul)
            tot=sets*(mul)/2
            nw=first+mul*sets
            tot+=max(min(r-nw+1,mul/2),0)
            gap=first-l
            gap-=(mul/2)
            tot+=max(0,gap)    
            d[i]=tot
        else:
            prev=first-mul
            tot=min(r,prev+mul/2)-max(prev,l)
            d[i]=tot
        mul*=2

    m=0
    for i in d:
        m=max(m,d[i])
    ans1=int(r-l+1-m)
    print(ans1)
    p='''d=dict()
    for i in range(l,r+1):
        s=bin(i)[2:]
        s=s[::-1]
        for i in range(len(s)):
            if s[i] =='1':
                if i in d:
                    d[i]+=1
                else:
                    d[i]=1
    m=0
    for i in d:
        m=max(m,d[i])
    ans2=(r-l+1-m)
    if ans1!=ans2:
        print("error",ans1,ans2,l,r)
    else:
        pass'''