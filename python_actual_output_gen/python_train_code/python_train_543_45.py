n,m=map(int,input().split())
for num	in input().split():
  n-=num
print(n if n>=0 else -1)