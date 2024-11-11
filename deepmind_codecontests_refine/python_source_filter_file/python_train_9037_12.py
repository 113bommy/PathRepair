N = int(input())
ans = 0
prior = 0
for i in range(N):
  a = int(input())
  if i == 0 and a != 0:
    ans = -1
    break
  if a == 0:
    prior = a
  elif a == 1:
    prior = a
    ans += 1
  elif a == prior + 1:
    ans += 1
    prior = a
  elif a == prior:
    ans += a
    prior = a
  else:
    ans = -1
    break
print(ans)