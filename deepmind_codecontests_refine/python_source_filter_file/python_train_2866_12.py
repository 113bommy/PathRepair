s = list(input())
t = list(input())
cnt = 0
for i in range(len(t), len(s)):
    if s[i-len(t):i] == t:
        s[i-1] = '#'
        cnt += 1
print(cnt)