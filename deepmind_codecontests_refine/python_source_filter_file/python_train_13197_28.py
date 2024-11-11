N=int(input())
a=list(map(int,input().split()))
a.sort()
ans=a[-1]
for i in range(N-2):
  ans+=a[-i//2-2]
print(ans)