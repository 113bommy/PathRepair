n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
a.reverse()
if a[m-1]>=sum(a)/4/m:
    print('Yes')
else:
    print('No')
