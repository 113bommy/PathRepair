N,K=map(int,input().split())
S=[0]*N
for _ in[0]*K:
 a,b=map(int,input().split())
 S[a-1]=b
dp=[0]*9
st,nd=S[:2]
if st:
 if nd:dp[~-st*3+~-nd]=1
 else:dp[~-st*3:st*3]=[1]*3
elif nd:dp[~-st::3]=[1]*3
else:dp=[1]*9
for i in range(2,N):
 cur=S[i]-1;tmp=[0]*9
 if cur>0:
  for k in range(3):tmp[k*3+cur]=sum(dp[k::3])-dp[cur*4]*(k==cur)
 else:
  for cur in range(3):
   for k in range(3):tmp[k*3+cur]=sum(dp[k::3])-dp[cur*4]*(k==cur)
 dp=tmp[:]
print(sum(dp)%10000)
