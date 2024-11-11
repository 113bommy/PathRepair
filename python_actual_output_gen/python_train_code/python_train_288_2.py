N = int(input())

def solve(a, i, prev):
  r = N - len(prev) - i + 1
  p = -i*a
  for j, s in enumerate(prev):
    yield max(p+abs(j-i)*a, s+abs(j+r)*a)
    p = s
  yield s+abs(len(prev)-i)*a

pd = [0]
A = map(int, input().split())
for a,i in sorted(((a, i) for i, a in enumerate(A, 1)), reverse=True):
  pd = [*solve(a,i, pd)]

print(max(prev))
