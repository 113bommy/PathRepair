n,t=map(int,input().split())
lst=list(map(int,input().split()))
s,j=0,0
for i in range(n):
  s=s+lst[i]
  if s>t:
    s=s-lst[i]
    j=j+1
print(n-j)