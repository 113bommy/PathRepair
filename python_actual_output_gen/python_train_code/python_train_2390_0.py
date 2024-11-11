n = int(input())
s = input()
cnt = 0
for i in range(len(s))[n::n]:
  if s[n-1]==s[n-2] and s[n-1] == s[n-3]:
    cnt += 1
print(cnt)
