N=int(input())
A=list(map(int,input().split()))
Q=int(input())
l=[0]*1000000
ans=sum(A)

for i in A:
  l[i]+=1

for i in range(Q):
  b,c=map(int,input().split())
  ans=ans+(c-b)*l[b]
  l[c]+=l[b]
  l[b]=0
  print(ans)