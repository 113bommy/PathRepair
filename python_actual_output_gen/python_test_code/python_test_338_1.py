# cook your dish here
n=int(input())
a=[int(k) for k in input().split()]
if(len(a) == 1):
    print(a[0])
else:
    d=[a[0],a[1]]
    c=a[0]^a[1]
    for i in range(2,n):
        while(len(d) > 0 and a[i] > d[-1]):
            d.pop()
        d.append(a[i])
        if(len(d) > 1):
            c=max(c,d[-1]^d[-2])
    d=[a[-1],a[-2]]
    e=max(c,a[-1]^a[-2])
    for i in range(n-2,0,-1):
        while(len(d) > 0 and a[i] > d[-1]):
            d.pop()
        d.append(a[i])
        if(len(d) > 1):
            e=max(c,d[-1]^d[-2])
    print(e)