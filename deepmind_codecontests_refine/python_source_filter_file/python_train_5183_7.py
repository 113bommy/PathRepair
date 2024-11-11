def main():
    N = int(input())
    A = list(map(int, input().split()))
    a0, a1, a2, b0, b1, b2 = 0, 0, 0, 0, 0, 0
    for i, a in enumerate(A):
        a0, a1, a2, b0, b1, b2 = (
                b0,
                max(b1, a0),
                max(b2, a1),
                a0 + a,
                a1 + a if i >= 1 else a1,
                a2 + a if i >= 2 else a2)

    if N & 1:
        return max(a2, b1)
    else:
        return max(a1, b0)


print(main())
