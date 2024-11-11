N, M = map(int,input().split(' '))
a = set([int(input()) for i in range(M)])
ans = [0]*(N+1)
ans[0] = 1
for i in range(1,N+1):
  if i in a:
    ans[i] = 0
  else:
    ans[i] = (ans[i-1]+ans[i-2])%(10**9+7)
print(ans[N])