def cal_pow(a, b):
    if b == 0: return 1

    res = cal_pow(a, b // 2)
    res = res * res % 1000000007

    if b % 2 == 1:
        res = (res * a) % 1000000007

    return res

n = int(input())
res = cal_pow(2, n)
print(((res * (res + 1) // 2)) % 1000000007)