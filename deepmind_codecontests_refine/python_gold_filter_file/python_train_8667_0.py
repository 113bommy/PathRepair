def check1(dpp):
  if dpp[8]>=1 or dpp[4]>=2:
    return "YES"
  elif dpp[6]>=1  and dpp[2]>=2:
     return "YES"
  elif dpp[4]>=1 and dpp[2]>=3:
     return "YES"
  else:
    return "NO"
       
n=int(input())
dp=[0]*(1000000)
dpp=[0]*(2*1000000)
arr=list(map(int,input().split()))
for i in arr:
  dp[i]+=1
  dpp[dp[i]]+=1
for _ in range(int(input())):
  a,b=input().split()
  if a=='+':
    i=int(b)
    dp[i]+=1
    dpp[dp[i]]+=1
    print(check1(dpp))
  if a=='-':
    i=int(b)
    dpp[dp[i]]-=1
    dp[i]-=1
    print(check1(dpp))
    
    
