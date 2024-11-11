n = input()
x = int(n[-1])
ans = 1 + 2 ** (x % 4) + 3 ** (x % 4) + 4 ** (x % 2)
ans = ans % 5
print(ans)