import collections as cc
d=cc.defaultdict(int)
c=cc.defaultdict(int)
h=input()
s=input()
for i in h:
    d[i]+=1
for i in s:
    c[i]+=1
fl=1
for i in s:
    if i==' ':
        continue
    elif d[i]<c[i]:
        fl=0
        break
print("YES") if fl else print("NO")
        
    
