N, M = map(int, input().split())
cy = [1] * M
city = []

for i in range(M):
  p, y = map(int, input().split())
  city.append((y, p, i))
city.sort()

ans = [""] * M

for y, p, i in city:
  ans[i] = ("000000" + str(p))[-6:] + ("000000" + str(cy[p-1]))[-6:]
  cy[p-1] += 1

print(*ans, sep="\n")