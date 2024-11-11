n = int(input())
xl = [list(map(int, input().split())) for i in range(n)]
xl = sorted([[x-l,x+l] for x,l in xl], key = lambda x: x[1])
now = - 10 ** 10
ans = 0
for s,e in xl:
  if s >= now:
    ans += 1
    now = e
print(ans)