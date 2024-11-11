l,r,a=[int(i) for i in input().split()]
if l>=r:
    if (l-r)>a:
        print((r+a)*2)
    elif (l+r+a)%2==0:
        print(l+r+a)
    else:
        print(l+r+a-1)
if r<l:
    if (r-l)>a:
        print((l+a)*2)
    elif (l+r+a)%2==0:
        print(l+r+a)
    else:
        print(l+r+a-1)
