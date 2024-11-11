t=int(input())
for _ in range(t):
  n,r=map(int,input().split())
  if n>r:
    print((r*(r+1))//2)
  else:
    print(1+(n*(n-1))//2)