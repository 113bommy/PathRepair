n,m=[int(x) for x in input().split()]
l1,l2=[],[]
for i in range(m):
    a,b=input().split()
    l1.append(int(a))
    l2.append(int(b))
l2, l1 =(list(t) for t in zip(*sorted(zip(l2, l1))))
l1=l1[::-1]
l2=l2[::-1]
c,s=0,0
for i in range(m):
    s+=l1[i]
    if(s<=n):
        c+=(l1[i]*l2[i])
    else:
        c+=((n-m)*l2[i])
        break
    m=s
print(c)