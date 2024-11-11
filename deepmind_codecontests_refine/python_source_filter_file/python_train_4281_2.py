from sys import stdin, stdout


def BigMod(a, b, m):
    if b == 0:
        return 1 % m

    x = BigMod(int(a), int(b / 2), int(m))
    x = (x * x) % m

    if b % 2 == 1:
        return (x * a) % m
    return x


n, m = map(int, stdin.readline().split())
ch = stdin.readline()

base = [1 for i in range(n + 1)]
pw = [1 for i in range(n + 1)]
cum = [0 for i in range(n + 1)]

# print(len(cum))

for i in range(n):
    cum[i + 1] = cum[i]
    if ch[i] == '1':
        cum[i + 1] += 1
    # print(cum[i])

Mod = 1e9 + 7

pw[0] = int(1)

for i in range(1, n + 1):
    pw[i] = int(int(pw[i - 1] * 2) % Mod)
    # print(pw[i])

for i in range(1, n + 1):
    base[i] = ((base[i - 1] % Mod) + (pw[i] % Mod)) % Mod
    # print(base[i])

while m > 0:
    l, r = map(int, stdin.readline().split())
    cur = cum[r] - cum[l - 1]
    m -= 1

    if cur == 0:
        stdout.write("0" + '\n')
        continue

    ans = int(((base[cur - 1] % Mod) * (pw[int((r - l + 1) - cur)] % Mod)) % Mod)
    stdout.write(str(ans) + '\n')

