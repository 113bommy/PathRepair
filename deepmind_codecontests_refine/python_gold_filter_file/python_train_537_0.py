kolvo = int(input())
for  i in range(kolvo):
    n, k, d = [int(x) for x in input().split()]
    vivod = n
    ser = input().split()
    for spi in range(n - d + 1):
        sp = []
        for dn in range(d):
            sp.append(ser[spi+dn])
        sp = list(set(sp))
        if len(sp) <= vivod:
            vivod = len(sp)
    print(vivod)