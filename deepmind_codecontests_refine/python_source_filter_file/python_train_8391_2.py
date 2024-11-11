n, m = map(int, input().split(' '))
n -= 1
minAps = 0
maxAps = 100000
for i in range(m):
    k, f = map(int, input().split(' '))
    k -= 1
    f -= 1
    if f == 0:
        minAps = max(minAps, k + 1)
    else:
        minAps = max(minAps, (k + f) // (f + 1))
        maxAps = min(maxAps, k // f)

minFloor = n // maxAps
maxFloor = n // minAps
if minFloor == maxFloor:
    print(minFloor + 1)
else:
    print(-1)
