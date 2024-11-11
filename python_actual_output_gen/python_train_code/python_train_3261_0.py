n=int(input())
a=list(map(int,input().split()))
a.sort()

b=len(a)
Z=a[-1]
X=0
for i in range(1,N-1):
  if abs((Z/2)-A[X])>abs((Z/2)-A[i]):
    X=i



print(a[-1],a[X])
