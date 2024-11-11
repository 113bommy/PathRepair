n=int(input())
out=0
for i in range(n):
  a,m=map(int,input().split())
  out+=m-a+1
print(out)

