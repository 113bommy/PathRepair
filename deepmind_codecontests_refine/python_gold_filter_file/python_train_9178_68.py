inp = [int(x) for x in input().split()]
H = inp[0]
L = inp[1]
A = ((L ** 2) - (H ** 2)) / (2 * H)
print("{p:.7f}".format(p = A))