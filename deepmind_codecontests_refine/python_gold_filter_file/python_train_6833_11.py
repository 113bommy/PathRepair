n, k = [int(x) for x in input().split()]
if(k == 1):
    print(n)
else:
    a = bin(n)[2:]
    print((1 << len(a)) - 1)