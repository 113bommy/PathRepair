d, goal = map(int, input().split())
pc = [0] + [list(map(int, input().split())) for _ in range(d)]

def solve(goal, d):
  if d == 0:
    return 10**9
  n = min(goal//(100*d), pc[d][0])
  t = n * d * 100
  if n == pc[d][0]:
    t += pc[d][1]
  if t < goal:
    n += solve(goal-t, d-1)
  return min(n, solve(goal,d-1))

print(solve(goal,d))
