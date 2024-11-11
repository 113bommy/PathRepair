from collections import Counter
x=int(input())
l=[]
for i in range(x):
    l.append(input())
c=Counter(l)
print(c)
print(  max(c,key=c.get) )
