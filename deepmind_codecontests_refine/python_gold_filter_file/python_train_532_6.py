n,m,k=[int(i) for i in input().split()]
ls=[int(i) for i in input().split()]
ls.insert(0,0)
le=[int(i) for i in input().split()]
le.insert(0,0)
lk=[int(i) for i in input().split()]
d=dict()
for i in range(1,len(ls)):
    if le[i] in d.keys():
        if ls[i]>d[le[i]]:
            d[le[i]]=ls[i]
    else:
        d[le[i]]=ls[i]
nb=0

for i in lk: 
    if (d[le[i]]!= ls[i]):
        nb+=1

print(nb)
