n= int(input())
l=[int(i) for i in input().split()]
ones=l.count(1)
i=0
if 1 in l:
    i=1
c=1
while i<ones:
    ind=l.index(1)
    i+=1
    l.pop(ind)
    nind=l.index(1)
    c*=(nind-ind+1)
if i==1 or i==0:
    print(i)
else:print(c)