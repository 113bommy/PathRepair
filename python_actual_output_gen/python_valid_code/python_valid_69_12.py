n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(k-1):
  if a[k+i]>a[i]:
    print("Yes")
  else:
    print("No")