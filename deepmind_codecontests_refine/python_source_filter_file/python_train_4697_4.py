a = list(map(int,input().split()))
a.sort()
if (a[2]-a[0]-a[1])>0:
    print(a[2]-a[0]-a[1]+1)
else:
    print(0)
