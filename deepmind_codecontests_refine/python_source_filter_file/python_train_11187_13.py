n,k=[int(x) for x in input().split()]
m=[int(x) for x in input().split()]
a=1
b=max(m)
c=min(m)
w=[]
while a<=k and b>c:
    p=m.index(b)
    q=m.index(c)
    w.append([p+1,q+1])
    m[p]-=1
    m[q]+=1
    b=max(m)
    c=min(m)
    a+=1
print(b-c,end=' ')
print(a)
for c in w:
    print(' '.join(map(str,c)))
