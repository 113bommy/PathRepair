def f_pow(a, n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    if n % 2 == 0:
        return f_pow(a * a, n // 2)
    else:
        return a * f_pow(a, n - 1)


def get_c(n):
    if(n > 68):
        return int(1e40)
    return (f_pow(4, n) - 4) // 12

def get_cc(n):
    if(n > 51):
        return int(1e30)
    return (f_pow(4, n) - 4) // 12

def ans(n, k):
    side = n - 1
    way = 4
    cnt_all = get_c(n + 1)
    c = 2
    op = 1
    while (True):
        if k < op or side < 0:
            break
        way_blocks = way - 1
        if(get_cc(side - 1) > k):
            return side
        per_block = get_cc(side + 1)
        kk = k - op
        if cnt_all - way_blocks * per_block - op >= kk:
            return side

        side -= 1
        op += (1 << c) - 1
        c += 1
        way *= 2
    return -1

def read():
    return [int(i) for i in input().split()]


t = int(input())

for i in range(t):
    n, k = read()
    a = ans(n, k)
    if(a == -1):
        print("NO")
    else:
        print("YES {}".format(a))