def df(s):
    x = sum(list(map(int, list(str(s)))))
    if x < 10:
        return x
    return df(x)

def main():
    def f(k, d):
        if k == 1:
            return str(d)
        if d == 1:
            x = "9" * (k - 1)
            xx = int(x) * 10
            for i in range(9):
                if df(xx + i) == d:
                    return xx + i
        a = ""
        b = ""
        if d // 2 != 0:
            a = f(k // 2, d // 2)
            if a == "No solution":
                return a
            b = f((k + 1) // 2, (d + 1) // 2)
            if b == "No solution":
                return b
            return str(a) + str(b)
        return "No solution"
    (k, d) = map(int, input().split(' '))
    return f(k, d)

print(main())
