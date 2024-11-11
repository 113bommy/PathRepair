n,k=map(int,input().split())
a=list(map(int,input().split()))
for i in range(1,k):
  if a[i]>a[i-1]:
    print("Yes")
  else:
    print("No")