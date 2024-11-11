s = input()

n = len(s)
p = s[::2].count("1") + s[1::2].count("0")

ans = min(n-p, n)
print(ans)
