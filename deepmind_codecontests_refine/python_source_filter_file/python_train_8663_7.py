s=input()
import collections
d=collections.defaultdict(list)
MAX=0
for i,x in enumerate(s):
    d[x].append(i)
    MAX=max(len(d[x]), MAX)

for x in d:
    for y in d:
        j=0
        count=0
        
        y=d[y]
        for i in d[x]:
            while j!=len(y) and y[j]>=i:
                j+=1
            if j==len(y):
                break
            count+=len(y)-j
            
        MAX=max(MAX,count)
print(MAX)