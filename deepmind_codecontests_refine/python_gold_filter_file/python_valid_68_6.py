t = int(input())
for u in range(t):
    n, dau, cuoi, giua, k, pos = int(input()), 1, 1, 1, 1, 1
    if n == 1: print("1 1")
    else:
        while cuoi < n: cuoi, dau, k, pos = cuoi + k + 2, dau + k, k + 2, pos + 1
        giua = (cuoi + dau) // 2
        if n < giua: print(pos - giua + n, pos)
        else: print(pos, pos - n + giua)