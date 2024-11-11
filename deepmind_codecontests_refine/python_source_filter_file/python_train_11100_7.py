n,k = map(int,input().split())
z = k
a = list(map(int,input().split()))
if(n-1<=k):
    print(max(a))
else:
    while(k>0):
        if(a[0]>a[1]):
            a[0],a[1]=a[1],a[0]
            l = a[0]
            a.pop(0)
            a.append(l)
            k-=1
        else:
            l = a[0]
            a.pop(0)
            a.append(l)
            k = z
    print(a[0])
