n = int(input())
dp = [0 for i in range(0, 2010)]
res = 0
for i in range(n): 
  s = input().split()
  a = int(s[1])
  if s[0] == 'win':
    dp[a] = 2**a + res
  else:
    ans = max(dp[a], res)

print(res)
# Sun Mar 24 2019 15:03:38 GMT+0300 (MSK)
