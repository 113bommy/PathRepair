s, w = map(int, input().split())
res = "unsafe" if s <= 2 * w else "safe"
print(res)
