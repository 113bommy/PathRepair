n = int(input())
*l, = map(int,input().split())
ans = 0
for i in range(n-1):
  if l[i] == i+1:
    l[i+1] = l[i]
    ans += 1
if l[-1] = n:
  ans += 1
print(ans)