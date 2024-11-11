mod = 10 ** 9 + 7
p, k = [int(x) for x in input().split()]
if k == 0:
    print(pow(p, p, mod))
elif k == 1:
    print(pow(p, p - 1, mod))
else:
    z = [1]
    while z[-1] * k % p != z[0]:
        z.append(z[-1] * k % p)
    print(pow(p, (p - 1) // len(z), mod))