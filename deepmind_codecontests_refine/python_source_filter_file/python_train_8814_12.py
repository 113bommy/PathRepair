#Duplicated from aman0309
x, k = [int(i) for i in input().split()]
if x == 0:
    print(0)
    exit()
p = int(10 ** 9 + 7)
x %= p
print((x * pow(2, k + 1, p) - pow(2, k, p) - 1) % p)