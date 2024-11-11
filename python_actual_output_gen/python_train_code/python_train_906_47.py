k,s = map(int,input().split())
ans = 0
for x in range(k+1):
  for y in range(k+1):
    z = s-x-y
    ans += (z and z <= k)
print(ans)