n, k = list(map(int, input().split()))
s = input()
chars = list(map(str, input().split()))
alphabets = list('abcdefghijlkmnopqrstuvwxyz')
memo = {alphabets[i]: 0 for i in range(26)}
for char in chars:
    memo[char] = 1
start = -1
answer = 0

for i in range(n):
    if memo[s[i]] and start < 0:
        start = i
    elif not memo[s[i]] and start >= 0:
        x = i - start
        answer += x * (x + 1) // 2
        start = -1
if start >= 0:
    x = n - start
    answer += x * (x + 1) // 2
print(answer)