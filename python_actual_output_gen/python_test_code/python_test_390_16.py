n = int(input())
ans = 0
for i in range(1,n+1):
  if n%3 and n%5:
    ans += i
print(ans)
