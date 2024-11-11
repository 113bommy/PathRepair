sum, xor = map(int, input().split())

andr = (sum-xor)/2

if sum < xor or (sum-xor) % 2 == 1 or int(andr) & xor == 1:
    print(0)
else:
    perm = 2 ** bin(xor).count("1")
    if sum == xor:
        perm = perm - 2
    print(perm)