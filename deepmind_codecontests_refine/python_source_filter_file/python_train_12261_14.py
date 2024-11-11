s =input()
ans = 0

for i in range(3):
  p = "R"*i
  if p in s:
    ans = i
print(ans)