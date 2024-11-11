k = int(input())
i = 1
while k > 9 * 10 ** (i - 1):
    k -= 9 * 10 ** (i - 1)
    i += 1

j = (k - 1) // i
k = k - j * i


print(str(10 ** (i - 1) + j)[k - 1])