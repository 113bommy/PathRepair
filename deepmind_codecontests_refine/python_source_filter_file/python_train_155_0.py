n,k=map(int,input().split())
a,b,c,d=map(int,input().split())
if k==n-1 or n==4:
  print(-1)
  exit()
ans=[a,c]+[i for i in range(1,n+1) if i not in [a,b,c,d]]+[d,b]
print(*ans)
ans2=[c,a]+[i for i in range(1,n+1) if i not in [a,b,c,d]]+[b,d]
print(*ans2)