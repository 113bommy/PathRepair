N = int(input())
ans = "Yes"
for i in range(N):
  t, x, y = map(int,input().split())
  if(t < x+y and (t+x+y)%2 == 1):
    ans = "No"
    break
print(ans)