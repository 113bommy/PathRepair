n,k=map(int,input().split())
s=set()
for i in range(k):
  d=int(input())
  s=s|set(map(int,input().split()))
print(s)
ans=n-len(s)
print(ans)