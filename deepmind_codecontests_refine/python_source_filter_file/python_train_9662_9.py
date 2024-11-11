n=int(input())
h=list(map(int, input().split()))
ans=0
num=0
for i in range(n):
  if num<h[i]:
    ans+=h[i]-num
  cnt=h[i]
print(ans)