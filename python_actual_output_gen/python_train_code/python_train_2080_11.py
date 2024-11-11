h, w = map(int, input().split())
if h % 3 == 0 or w % 3 == 0:
    print(0)
    exit()
ans = 10 ** 10
for x in range(1, w):
    blocks = [h * x, h // 2 * (w - x), (h - h // 2) * (w - x)]
    ans = min(ans, max(blocks) - min(blocks))
for y in range(1, h):
    blocks = [w * y, w // 2 * (h - y), (w - w // 2) * (h - y)]
    ans = min(ans, max(blocks) - min(blocks))
print(ans)