n = int(input())
s = input()
dp = [0]*n
j = 1

for i in range(n):
    while s[i:j] in s[j:s]:
        j += 1
    dp[i] = j-i-1
print(max(dp))
