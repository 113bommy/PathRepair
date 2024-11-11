n,m=[int(x) for x in input().split()]
if m==0:
    print(1)
else:
    if m-1>=n//2:
        print(n-m)
    else:
        print(m)
