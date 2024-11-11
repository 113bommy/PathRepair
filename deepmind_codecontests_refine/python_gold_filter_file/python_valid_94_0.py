def check(num, i):
    ans = 1
    b = [0, 0]
    for j in range(8):
        b.append(i & 1)
        i = i >> 1
    flag=True
    for j in range(9, -1, -1):
        t=num[j]+(b[j + 2] * 10 if j + 2 < 10 else 0)
        if b[j] == 1 and t == 0:
            return 0
        tmp =t - b[j]
        if tmp>9:
            flag=False
        ans *= ((tmp + 1) if tmp < 10 else 19 - tmp)
    return ans-(2 if flag else 0)

for test in range(int(input())):
    n = int(input())
    num = [((n // (10 ** i)) % 10) for i in range(10)]
    ans = 0
    for i in range(2 ** 8):
        ans += check(num, i)
    print(ans)