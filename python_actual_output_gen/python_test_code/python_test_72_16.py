N,M = map(int, input().split())
s,p = [False]*N, [0]*N
for i in range(M):
  tmp = input().split()
  pi,Si = int(tmp[0])-1, tmp[1]
  s[pi] |= Si == "AC"
  p[pi] += 1 if not s[pi] else 0
print(sum(s), sum([pi for si,pi in zip(s,p) if s]))
