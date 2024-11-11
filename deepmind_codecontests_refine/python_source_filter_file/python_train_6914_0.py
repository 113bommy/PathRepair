n = int(input())

wallets = [int(inp) for inp in input().split()]

res = []

for s in range(wallets[0]):
    res.append("RLP")

if wallets[0] == 0:
    res.append("")

for w in range(n):
    res.append("R")
    for e in range(wallets[w]):
        res.append("LRP")
    if wallets[w] == 0:
        res.append("")

print(''.join(res))

