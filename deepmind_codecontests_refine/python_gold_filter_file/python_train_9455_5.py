n=int(input())
a=list(map(int,input().split()))
a.sort()

b=len(a)
Z=a[-1]
X=0
for i in range(1,n-1):
  if abs((Z/2)-a[X])>abs((Z/2)-a[i]):
    X=i



print(a[-1],a[X])
