
s, t = input().split()
res = s[0]
for c in s[1:]:
     if c >= t[0]:
          break
     res += c
print(res + t[0])
