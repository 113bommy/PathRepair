n, m, v, p = map(int, input().split())
A = list(map(int, input().split()))
A.sort(reverse=True)

ok = p - 1
ng = n

while ok - ng > 1:
  mid = (ok + ng) // 2
  if A[mid] + m < A[p - 1]:
    ng = mid
    continue

  used = m * p
  for i in range(p - 1, n):
    if i == mid:
      continue

    used += min(m, max(0, A[mid] + m - A[i]))

  if used >= m * v:
    ok = mid
  else:
    ng = mid

print(ok + 1)