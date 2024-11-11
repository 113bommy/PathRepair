R,G,B,N=map(int,input().split())
ans=0
for i in range(N//R + 1):
  for j in range(N//G + 1)
  if R*i+G*j <= N:
    if (N - (R*i+G*j))%B==0:
      ans+=1
print(ans)