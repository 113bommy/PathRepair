H, L = map(int, input().split())
ans = (H ** L + L ** 2) / (2 * H)
print(ans - H)