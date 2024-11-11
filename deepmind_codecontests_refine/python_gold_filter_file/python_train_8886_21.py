n = int(input())
s = list(input())
t = 0
i = 0
for i in range(1, len(s)):
    if s[i] == s[i - 1]:
        t += 1
print(t)
