N = int(input())
A, B = map(int, input().split())
P = list(map(int, input().split()))
ans = [0] * 21

for i in range(N):
  ans[P[i]] += 1

print(min(sum(ans[0:A + 1]), sum(ans[A:B + 1]), sum(ans[B:])))
