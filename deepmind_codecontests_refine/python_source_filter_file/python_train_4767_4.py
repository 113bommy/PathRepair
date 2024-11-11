def f_modularness():
    K, Q = [int(i) for i in input().split()]
    D = [int(i) for i in input().split()]
    Queries = [[int(i) for i in input().split()] for j in range(Q)]

    def divceil(a, b):
        return (a + b - 1) // b

    ans = []
    for n, x, m in Queries:
        last, eq = x, 0  # 末項、D_i % m == 0 となる D_i の数
        for i,d in enumerate(D):
            num = divceil(n - 1 - i, K)  # D_i を足すことは何回起きるか？
            last += (d % m) * num
            if d % m == 0:
                eq += num
        ans.append((n - 1) - (last // m - x // m) - eq)
    return '\n'.join(map(str, ans))

print(f_modularness())