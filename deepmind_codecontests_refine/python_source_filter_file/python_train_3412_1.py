K = int(input())
a = 7
ans = -1
for i in range(1,10**6+1):
  if a%K==0:
    ans = i
    break
  a = a*10+7
print(ans)