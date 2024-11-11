import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
cx, cy = [0]*k, [0]*k
tx, ty = [0]*k, [0]*k

for i, (x, y) in enumerate(map(int, input().split()) for _ in range(k)):
    cx[i] = x
    cy[i] = y

for i, (x, y) in enumerate(map(int, input().split()) for _ in range(k)):
    tx[i] = x
    ty[i] = y

ans = 'L'*(n-1) + 'U'*(m-1)
for i in range(m):
    if i % 2 == 0:
        ans += 'R'*(n-1)
    else:
        ans += 'L'*(n-1)
    ans += 'D'

print(len(ans))
print(ans)
