def fun(n):
    ops = 0
    while n:
        pc = format(n, 'b').count('1')
        n %= pc
        ops += 1
    return ops

n = int(input())
xs = input()

sm = int(xs, 2)
pc = xs.count('1')

mp = sm % (pc + 1)
mm = sm % (pc - 1) if pc > 1 else 0

for i, x in enumerate(xs, 1):
    df = 1 if x == '1' else -1
    pci = pc + df
    if pci == 0:
        print(0)
        continue

    rest = pow(2, n - i, pci)

    if x == '0':
        smi = (mp + rest) % pci
        print(1 + fun(smi))
    else:
        smi = (mm - rest) % pci
        print(1 + fun(smi))
