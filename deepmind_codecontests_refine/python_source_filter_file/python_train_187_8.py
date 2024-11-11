N = int(input())
F = [int(input().replace(' ', ''), 2) for _ in range(N)]
P = [list(map(int,input().split())) for _ in range(N)]


print(N,F,P)

ans = -(10**9+7)
for i in range(1, 2**10):
  tmp = 0
  for f, p in zip(F, P):
    tmp += p[bin(f&i).count('1')]
    #print(f,i,p[bin(f&i).count('1')])
  ans = max(ans, tmp)
print(ans)
