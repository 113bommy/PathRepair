n, m = map(int, input().split())
tvs = input().split(" ")
counts = 0
sum = 0
for i in range(n):
    tvs[i] = int(tvs[i])
tvs.sort()
for i in range(n):
    if counts > m or tvs[i] > 0:
        break
    else:
        sum += abs(tvs[i])
        counts += 1

print(sum)