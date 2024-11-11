N = int(input())
tmp1 = 2
tmp2 = 2
for i in range(1, N + 1):
    if i == 1:
        print(2)
        tmp2 *= 3
    else:
        print(tmp2 ** 2 - tmp1)
        tmp1 = tmp2
        tmp2 //= i
        tmp2 *= (i + 2)
