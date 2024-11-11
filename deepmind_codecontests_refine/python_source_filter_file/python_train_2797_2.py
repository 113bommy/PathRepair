c=0
for W in iter(input,'0\n'):
 c+=1
 W=int(W)
 dp=[0]*-~W
 for _ in[0]*int(input()):
  v,w=map(int,input().split(','))
  for i in range(W,w-1,-1):
   if dp[i]<dp[i-w]+v:dp[i]=dp[i-w]+v
 for i in range(W+1):
  if dp[W]==dp[i]:print(f'Case {c}:\n{dp[W]}\n{i}');break
