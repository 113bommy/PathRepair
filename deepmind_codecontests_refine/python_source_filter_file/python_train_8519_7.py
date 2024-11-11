n=int(input())
a=list(map(int,input().split()))
M=max(a)
m=min(a)
if M>m+1:
  print("No")
elif M==m+1:
  cntm=a.count(m)
  cntM=n-cntm
  if cntm>m:
    print("No")
  elif cntm+cntM//2<M:
    print("No")
  else:
    print("Yes")
elif M==m:
  if m<=n//2:
    print("Yes")
  else if m==n-1:
    print("Yes")
  else:
    print("No")