import math

def hersCode(N):
  ng = -1
  ok = N
  while ok -  ng > 1:
    mid = (ok + ng) // 2
    if judge(mid):
      ok = mid
    else:
      ng = mid
  return ok

def judge(x):
  cnt = 0
  for i in h:
    cnt += math.ceil((i - x * B) / (A - B))
  return cnt <= x


N, A, B = list(map(int, input().split()))
h = [int(input()) for _ in range(N)]

print(hersCode(10 ** 9))



