N, M = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
cnt = 0
for a in A:
  M -= a
  if M >= 0:
    cnt += 1.
  else:
    break
if M > 0:
  cnt -= 1
print(cnt)