n=int(input())
a=list(map(int,input().split()))
x=sum(a)
S=0
ans=2020202022
for i in range(n):
  S+=a[i]
  if abs((x-S)-S) < ans:
    ans=abs((x-S)-S)
print(ans)