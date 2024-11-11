n,m= map(int,input().split())
if m!=0:
    a=[int(x) for x in input().split()]
    a.sort()
    an=0
    if 1 in a or n in a:
        an=-1
    for i in range(m-2):
        if a[i+1]==a[i]+1 and a[i+2]==a[i]+2:
            an=-1
            break
    if an==0:
        print("YES")
    else:
        print("NO")
else:
    print("YES")