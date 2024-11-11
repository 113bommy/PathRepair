N,K=map(int,input().split())
Alist=list(map(int,input().split()))
for i in range(0,N):
  if Alist[i]<Alist[i+K]:
    print("Yes")
  else:
    print("No")