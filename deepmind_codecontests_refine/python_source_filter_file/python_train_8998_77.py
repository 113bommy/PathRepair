n = '0' + input()
x = int(n[-2])
ans = 1 + 2 ** (x % 4) + 3 ** (x % 4) + (- 1) ** (x % 2)
ans = ans % 5
print(ans)