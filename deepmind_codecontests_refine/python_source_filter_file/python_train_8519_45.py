import bisect
n=int(input())
a=list(map(int,input().split()))
s=max(a)-min(a)
if s>=2:
    print("No")
elif s==0:
    if a[0]==n-1 or n/a[0]>=2:
        print("Yes")
    else:
        print("No")
else:
    a.sort()
    x=bisect.bisect_right(a,a[0])
    if x<=a[-1]<=x+(n-x)//2 and n-x>=2:
        print("Yes")
    else:
        print("No")