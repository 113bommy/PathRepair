
s, t = input().split()
i = j = 0
n = len(s)
while i < n and s[i] < t[0]:
     i += 1
print(s[:i] + t[0])
