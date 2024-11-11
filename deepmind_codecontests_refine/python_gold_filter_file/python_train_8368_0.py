MOD = int(1e9 + 7)
x = input()[::-1]
n = len(x)
res = 0
for i, t in enumerate(x):
    if t == '1':
        res = (res + (1 << (n - 1 + i))) % MOD
print(res)
