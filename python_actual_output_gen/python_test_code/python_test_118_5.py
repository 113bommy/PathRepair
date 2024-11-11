k=int(input().split()[1])
d={}
p=l=0
for c in input():
 if c!=p:d[p]=d.get(p,0)+l//k;l=0;p=c
 l+=1
print(max(d.values()))