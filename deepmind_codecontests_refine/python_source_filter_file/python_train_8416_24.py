N,x=map(int,input().split())
A=list(map(int,input().split()))
cnt=0
for i in range(N-1):
  a=A[i]+A[i+1]
  if a>x:
    if (x-a)>A[i+1]:
      A[i+1]==0
    else:
      A[i+1]-=(a-x)
    cnt+=(a-x)
print(cnt)