m, d = map(int, input().split())
mes = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
print((mes[m - 1] + d + 6) // 7)