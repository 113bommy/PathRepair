s=input()
d=list(map(int,s.split(' ')))
l=d[0]
c=m=d[1]
t=input()
s=[]
p=[]
o=[]
for h in range(0,l):
    p.append(t[h])
    if(t[h] not in o):
        o.append(t[h])
o.sort()
def polo(r):
    for y in range(0,len(o)):
        if(t[r]==o[y]):
            return(o[y+1])
            break
if(l<m):
    t=t+o[0]*(m-l)
    print(t)
else:
    s=p[0:m-1]
    if(t[m-1]!=o[len(o)-1]):
        s.append(polo(m-1))
        s=''.join(map(str,s))
    else:
        s.append('k')
        while(t[m-1]==o[len(o)-1]):
            del(s[m-1])
            m=len(s)
        del(s[m-1])
        s.append(o[len(o)-1])
        s=''.join(map(str,s))
        s=s+o[0]*(c-m)
    print(s)