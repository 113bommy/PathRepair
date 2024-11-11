N = int(input())
cnt=0
for _ in range(N):
  l,r = map(int,input().split())
  cnt+=(1+(r-l))
print(cnt)