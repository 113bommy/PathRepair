N=int(input())
a=list(map(int,input().split()))

ball=[0]*N
for i in range(N-1,-1,-1):
  B=ball[i::i+1]
  if sum(B)!=a[i]:
    ball[i]=1

print(sum(ball))
if sum(ball)!=0:
  b=[]
  for i in range(N):
    if ball[i]==1:
      b.append(i+1)
  print(*b)