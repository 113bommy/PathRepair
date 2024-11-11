# ARC076C - Reconciled?
def factorial_mod(x):
    MOD = 10 ** 9 + 7
    ret = 1
    for i in range(1, x + 1):
        ret = (ret * i) % MOD
    return ret


def main():
    n, m = list(map(int, input().rstrip().split()))
    MOD = 10 ** 9 + 7
    n, m = min(n, m), max(n, m)
    dif = m - n
    if dif > 1:  # must be ...DDM...
        print(0)
    else:
        if dif == 0:  # start with either D or M (DM..., MD...)
            ans = (factorial_mod(n) ** 2 * 2) % MOD
        else:  # sandwich (DMD or MDM)
            ans = (factorial_mod(n) ** 2 * m) % MOD
        print(ans)


if __name__ == "__main__":
    main()