s = input()
cnt = 0
for i in range((n+1)//2):
  if s[i] != s[n-i-1]:
    cnt += 1
print(cnt)