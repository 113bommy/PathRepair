
s, t = input().split()
i = 1
n = len(s)
while i < n and s[i] < t[0]:
     i += 1
print(s[:i] + t[0])
