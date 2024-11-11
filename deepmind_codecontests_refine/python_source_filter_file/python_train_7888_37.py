N = int(input())
R = []

for i in range(N):
    x, l = map(int, input().split())
    R.append((x - l, x + l))

R.sort()

l = -(1 << 40)

cnt = 0
for r in R:
    if l <= r[0]:
        cnt += 1
        l = r[1]

print(cnt)

