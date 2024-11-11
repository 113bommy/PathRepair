n = int(input())
s = input()
dp = [0]*n
j = 1

for i in range(n):
    while S[i:j] in S[j:s]:
        j += 1
    dp[i] = j-i-1
print(max(dp))