s=input()
c=dict.fromkeys(list('abcdefghijklmnopqrstuvwxyz'),0)
r=dict.fromkeys(list('abcdefghijklmnopqrstuvwxyz'),0)
for i in range(len(s)):
    a=s[i]
    x=i-c[a]
    if x>r[a]:
        r[a]=x
    c[a]=i
d=len(s)
for i in c.keys():
    x=d-c[i]
    if x>r[i]:
        r[i]=x
#for i in r.values():
#    if (i!=0) and (i<d):
#        d=i
d=min(r.values())
print(d)