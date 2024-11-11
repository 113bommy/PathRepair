N,K =map(int,input().split())
List = list(map(int,input().split()))
DP = [False]*(2*K+1)
for i in range(K):
  for item in List:
    if DP[i]==False:
      DP[i+item] = True
if DP[k]==True:
  print('First')
else:
  print('Second')