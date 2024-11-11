## 6点、5点を繰り返すのが最適

x = int(input())

ans = 2 * ((x - 1) // 11) + ((x - 1) % 11 > 6) + 1
print(ans)