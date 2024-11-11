n=int(input())
d,x=map(int,input().split())
ans=x
for i in range(n):
  k=int(input())
  print(k)
  ans+=(d-1)//k+1
print(ans)
