s = input().split('S')

ans = 0

for i in s:
  if len(s) > ans:
    ans = len(s)
    
print(ans)