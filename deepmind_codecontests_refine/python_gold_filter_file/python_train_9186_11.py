from sys import stdin, stdout


# 10
# 582366931603099761 314858607473442114 530263190370309150 871012489649491233 877068367969362781
# 671646356752418008 390155369686708364 958695211216189893 919124874293325142 196726357117434998
# res: 1152921229728939135
# 11100
# 10100

# if k = 3, result = a1 | a2 | a3
# if k > 3, if ith bit is set, then k == 3, ith bit is also set.
def maximum_sebsequence_value(n, a):
    res = 0
    for i in range(n):
        for j in range(i, n):
            for k in range(j, n):
                res = max(res, a[i] | a[j] | a[k])

    return res


if __name__ == '__main__':
    n = int(stdin.readline())
    a = list(map(int, stdin.readline().split()))

    stdout.write(str(maximum_sebsequence_value(n, a)) + '\n')
