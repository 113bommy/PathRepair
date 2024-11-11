N = int(input())
A = [abs(int(input())) for _ in range(N)]
#A.sort()
s = sum(A)

def mulmod(p,q,mod):
  return ((p%mod)*(q%mod))%mod
def powermod(p,n,mod):
  if n==0: return 1
  if n==1: return p%mod
  else:    return powermod(p,n//2,mod)**2 * (p**(n%2)) %mod
def dividemod(p,q,mod):
  # modは素数
  return mulmod(p, powermod(q,mod-2,mod), mod)

mod = 998244353

dp = [[0]*(s+1) for _ in range(N)]
# dp[n][s] An-1(0-index)まで加えて、Rの和がsになるのが何通りか（残りのG,Bまで含めて）
dp[0][0] = 2
dp[0][A[0]] = 1
temp_sum = A[0]

for i in range(1,N):
  for j in range(A[i]):
    dp[i][j] = (dp[i-1][j]*2) %mod
  for j in range(A[i], temp_sum+1):
    dp[i][j] = (dp[i-1][j]*2 + dp[i-1][j-A[i]]) %mod
  for j in range(temp_sum+1, temp_sum+1 + A[i]):
    dp[i][j] = (dp[i-1][j-A[i]]) %mod
  temp_sum += A[i]


def part_sum(a,A):
  p=mod
  #初期化
  N=len(a)
  dp=[[0 for i in range(A+1)] for j in range(N+1)]
  dp[0][0]=1

  #DP
  for i in range(N):
    for j in range(A+1):
      if a[i]<=j: #i+1番目の数字a[i]を足せるかも
        dp[i+1][j]=dp[i][j-a[i]]+ dp[i][j]% p
      else: #入る可能性はない
        dp[i+1][j]=dp[i][j]%p
  return dp[N][A]

ps = part_sum(A, s//2)

if s%2 != 0:
    answer = (powermod(3, N, mod) - 3*sum(dp[N-1][(s+1)//2:]))%mod
else:
    answer = (powermod(3, N, mod) - 3*(sum(dp[N-1][(s+1)//2:]) - ps))%mod



print(answer)
