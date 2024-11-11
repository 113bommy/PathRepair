t = int(input())

out = {1: 1, 2: 3, 3: 6, 4: 10}
for _ in range(t):
    x = input() 
    xlen, xval = len(x), int(x)
    if xlen == 1:
        print(out[xlen] + 10 * (xval - 1))
    elif xlen == 2:
        print(out[xlen] + (xval // 11 - 1) * 10)
    elif xlen == 3:
        print(out[xlen] + (xval // 111 - 1) * 10)
    else:
        print(out[xlen] + (xval // 1111 - 1) * 10)
