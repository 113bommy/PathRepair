m,d = map(int,input().split())
ans = 0
for i in range(1,d+1):
  a = i%10
  b = i//10
  if a >= 2 and b >= 2 and a*b == m:
    ans += 1
print(ans)