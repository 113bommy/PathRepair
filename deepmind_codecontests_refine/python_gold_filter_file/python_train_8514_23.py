from bisect import *
s=input()
t=input()
a=[[]for i in range(26)]
for i in range(len(s)):
    a[ord(s[i])-97].append(i+1)
p=-1
b=[len(i)for i in a]
r=0
for i in t:
    if b[ord(i)-97]==0:
        print(-1)
        break
    c=bisect_right(a[ord(i)-97],p)
    if c==b[ord(i)-97]:
        r+=1
        p=a[ord(i)-97][0]
    else:
        p=a[ord(i)-97][c]
else:
    print(r*len(s)+p)