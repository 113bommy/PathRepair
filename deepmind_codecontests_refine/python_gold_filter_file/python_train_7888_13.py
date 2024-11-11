n = int(input())
X = []
for i in range(n):
    x, y = map(int, input().split())
    X.append((x - y, x + y))
X.sort(key=lambda x: x[1])
ter = -10**10
cnt = 0
for left, right in X:
    if ter <= left:
        ter = right
        cnt += 1
print(cnt)
