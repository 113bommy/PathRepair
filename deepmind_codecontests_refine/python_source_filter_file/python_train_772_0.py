s = input()
k = int(input())
m = len(s) + k
ans = 0
if k >= len(s):
  ans = m
for x in range(len(s)//2+1, 0, -1):
  for y in range(len(s)-2*x):
    if s[y:y+x] == s[y+x:y+2*x]:
      ans = max(ans, 2*x)
      # print(s[y:y+x], s[y+x:y+2*x])
for l in range(m//2, 0, -1):
  c = s[m-2*l:m-l]
  if c[:l-k] == s[m-l:]:
    ans = max(ans, 2*l)
    break
print(ans)