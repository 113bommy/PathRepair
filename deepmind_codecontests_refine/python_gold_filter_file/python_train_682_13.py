import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))
b = list(map(int, sys.stdin.readline().split()))
ans = 0

am = [0] * 5
bm = [0] * 5

for i in a:
    am[i - 1] += 1
for i in b:
    bm[i - 1] += 1

for i in range(5):
    if am[i] != bm[i]:
        if (am[i] - bm[i]) % 2 == 0:
            ans += abs(am[i] - bm[i]) // 2
        else:
            ans = -1
            break
print(ans // 2)
