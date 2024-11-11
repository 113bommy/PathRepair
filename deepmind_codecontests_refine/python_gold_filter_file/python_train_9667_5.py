H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

ans = "Impossible"

cnt = 0
for a in A:
    cnt += a.count("#")

if cnt == H + W - 1:
    ans = "Possible"

print(ans)