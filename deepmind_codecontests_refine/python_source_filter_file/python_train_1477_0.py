#E70_D

T = int(input())

for i in range(0, T):
    n = int(input())
    j = 0
    while j * (j - 1) / 2 < n:
        j += 1

    j -= 1

    r = int(n - (j * (j - 1) / 2))

    st = "1"

    for k in range(0, j):
        st += "3"

    st = list(st)
    st = st[:3] + ["7"] * r + st[3:] + ["7"]

    print("".join(st))

