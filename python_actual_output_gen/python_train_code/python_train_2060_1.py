ls=list(input())
d={}
for i in ls:
    d[i]=d.get(i,0)
count=0
for m in d.values():
    count+=m**2
print(count)