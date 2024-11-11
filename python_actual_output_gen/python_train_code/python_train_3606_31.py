n,a,b,c,d = map(int, input().split())
s = input()
ans = ["Yes","No"]
t = 0
if b < c:
  if "##" in s[min(a,b)-1:max(c,d)]:
    t = 1
else:
  if "##" in s[a-1:c] or "##" in s[b-1:d]:
    t = 1
if c > d:
  if not "..." in s[b-1:d]:
    t = 1
print(ans[t])