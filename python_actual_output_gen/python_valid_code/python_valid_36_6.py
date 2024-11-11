s = input()
ans = 0

for i in range(1,4):
  p = "R"*i
  if p in s:
    ans = i
print(i+1)