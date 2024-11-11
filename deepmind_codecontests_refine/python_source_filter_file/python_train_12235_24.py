
def bin_expo(b , p):
    res = 1
    while p > 0:
        if p & 1 :
            res = res * b
        b = b * b
        p = p >> 1
    return res


n = int(input())

res = bin_expo(4 , n - 3)

res = res * ((3 * 9) - 3)

print(int(res))