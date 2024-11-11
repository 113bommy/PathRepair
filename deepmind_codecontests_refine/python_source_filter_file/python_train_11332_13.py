N,M=map(int,input().split(' '))
A=[input() for x in range(N)]
B=[input() for x in range(M)]
ans = 'No'
for h in range(0,(N-M)+1):
  for w in range(0,(N-M)+1):
    if sum([B[i]!=A[i+h][w:(w+M+1)] for i in range(M)])==0:
      ans = 'Yes'
      break
  if ans == 'Yes':
    break
print(ans)