a = int(input())
s = "ROYGBIV"
if a > 7:
    print(s * (a // 7) + s[3:] * 2)
else:
    print(s[:a])
