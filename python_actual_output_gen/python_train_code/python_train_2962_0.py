def rewrite(string):
    return string[0:-len(string) - 1:-1]


k, p = map(int, input().split())
i = 11
s = 0
for i in range(1, k + 1):
    c = str(i)
    s += int(c + rewrite(c))
print(s % p)
