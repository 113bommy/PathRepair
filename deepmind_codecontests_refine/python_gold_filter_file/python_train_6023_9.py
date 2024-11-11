H, W = map(int, input().split())

ans = float('inf')
for _ in range(2):
    for i in range(1, H):
        a = i*W

        b = ((H - i) // 2) * W
        c = ((H - i + 1)// 2) * W
        ans = min(ans, abs(max(a, b, c) - min(a, b, c)))

        b = (W // 2) * (H -i)
        c = ((W + 1) // 2) * (H - i)
        ans = min(ans, abs(max(a, b, c) - min(a, b, c)))
    H, W = W, H
print(ans)