from macpath import curdir
import bisect
a=input()
b=input()
la=len(a)
lb=len(b)
forb=[la]*lb
cur=0
for i in range(lb):
    while cur<la and a[cur]!=b[i]:
        cur+=1
    if cur<la:
        forb[i]=cur
        cur+=1
    else:
        break
cur=la-1
bacb=[-1]*lb
for i in range(lb-1,-1,-1):
    while cur>=0 and a[cur]!=b[i]:
        cur-=1
    if cur>=0:
        bacb[i]=cur
        cur-=1
    else:
        break
res=lb
start=0
end=lb
for i in range(lb):
    low=-1
    if i>0 :
        low=forb[i-1]
    if low>=la:
        break
    j=bisect.bisect_right(bacb,low)
    if res>j-i:
        res=j-i
        start=i
        end=j
if res==lb:
    print('-')    
else:
    print(b[:start]+b[end:])
        
    
    
    