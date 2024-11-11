T=int(input())
for _ in range(T):
  N=int(input())
  arr=list(map(int,input().split()))
  for i in range(N):
    if(i&1):
      arr[i]=abs(arr[i])
    else:
      arr[i]=abs(arr[i])
    print(arr[i],end=' ')
 