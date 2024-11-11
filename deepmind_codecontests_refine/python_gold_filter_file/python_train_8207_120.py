x = int(input())
ans = (x - 1) // 11 * 2 + (1 if (x - 1) % 11 < 6 else 2)
print(ans)
