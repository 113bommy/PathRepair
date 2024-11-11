h, w = map(int, input().split())
ans = (h * w - 1) // 2
if h == 1 or w == 1:
    ans = 1
print(ans)
