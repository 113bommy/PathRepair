n=int(input())
a=sorted([int(input())for i in range(n)])
def f(x):
    p,q=1,n-2
    l,r=[a[0]],[a[n-1]]
    c=a[n-1]-a[0]
    t=0
    while p<=q:
        if t==x:
            r.append(a[q])
            c+=a[q]-l[0]
            q-=1
            l.pop()
        else:
            l.append(a[p])
            c+=r[0]-a[p]
            p+=1
            r.pop()
        t=(t+1)%2
    return c
print(max(f(0),f(1)))