for _ in " "*int(input()):
  n,a=int(input()),list(map(int,input().split()))
  for i in range(n):print(a[i]*(-1)**i,end=" ")
