N=int(input())
S=list(map(int, input().split()))
Min=10
ans=0
for i in S:
  if Min>i:
    Min=i
    ans+=1
    
print(ans)