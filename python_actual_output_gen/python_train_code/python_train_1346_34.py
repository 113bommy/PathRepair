n, m = map(int, input().split())
for i in range(1, m + 1):
    def fun(m):
        k = ""
        for j in range(m):
            k += "#"
        return k
    if i % 2 != 0:
        print(fun(m))
    else:
        if i % 4 == 0:
            print("#" + val(m))
        else:
            print(val(m) + "#")

    def val(m):
        k = ""
        for j in range(m - 1):
            k += "."
        return k

