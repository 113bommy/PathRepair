n=int(input())
l=list(map(int,input().split()))
l=[0]+l
s=sum(l)
k=int(input())
for _ in range(1,n+1):
  m,n=map(int,input().split())
  print(s-l[m]+n)
  
  