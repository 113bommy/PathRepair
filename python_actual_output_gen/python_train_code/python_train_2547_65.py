N=int(input())
answer=0
for i in range(N):
  l,r = map(input().split())
  answer+=r-l+1
print(answer)