n=int(input())
a=[int(w) for w in input().split()]
a.sort()
if a[-1]-a[0]==0:
    print(0,n*(n-1)//2)
else:
    print(a[-1]-a[0],a.count(a[0])*a.count(a[-1]))