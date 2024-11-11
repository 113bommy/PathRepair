n = int(input())
s = input()
res = ''
cnt = 0
for i in range(len(s)):
  if cnt >= len(s) - 1: break 
  res += s[cnt]
  cnt += i + 1
print(res)
