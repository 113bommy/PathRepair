H, W = map(int, input().split())
if H % 3 == 0 or W % 3 == 0:
    print(0)
    exit()
ans = H * W
for i in range(2):
    for h in range(1, H):
        s = [h * W, W // 2 * (H - h), (W - W // 2) * (H - h)]
        s2 = [h * W, (H - h) // 2 * W, ((H - h) - (H - h) // 2) * W]
        ans = min(ans, min(max(s) - min(s), max(s2) - min(s2)))
    H, W = W, H
print(ans)
