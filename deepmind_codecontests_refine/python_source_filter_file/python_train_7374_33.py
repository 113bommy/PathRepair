n=int(input())
out=0
for i in (n):
  n,m=map(int,input().split())
  out+=m-n+1
print(out)