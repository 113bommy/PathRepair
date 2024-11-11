import collections
l=list(input())
p=list(input())
#print(p)
#print(l)
cl=collections.Counter(l)
pl=collections.Counter(p)
#print(cl)
#print(pl)
plk=list(pl.keys())
#print(plk)
if ' ' in plk:
    plk.remove(' ')
else:
    pass
n=len(plk)
i=0
er=0
#print(cl['s'])
while i<n:
    h=plk[i]
    t=cl[h]
    q=pl[h]
    #print(t)
    #print(q)
    if t>=q:
        er+=1
    else:
        pass
    i+=1
#print(n)
#print(er)
if er==n:
    print('YES')

else:
    print('NO')


