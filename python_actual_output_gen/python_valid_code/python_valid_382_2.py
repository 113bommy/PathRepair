s = input()
n = len(s)
dp = [0]*26

for i in s:
  dp[ord(i) - ord('a')]+=1
#print(dp)
ans = 0
#重複する二つの文字分だけ減らして加える
for j in dp:
  ans += (j * (n-j))//2
print(ans+1)