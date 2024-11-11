n=int(input())
A=list(map(int,input().split()))
ans = [0]*8
r = 0
for i in range(n):
  if A[i] < 3200:
    ans[A[i]//400] = 1
  else:
    r += 1
print(*[sum(ans),sum(ans)+r])