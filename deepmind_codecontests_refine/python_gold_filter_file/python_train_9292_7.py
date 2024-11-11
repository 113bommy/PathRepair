from sys import stdin, stdout


def Boboniu_Chats_with_Du(n, d, m, a_a):

    b_a = []
    c_a = []
    res = 0

    for a in a_a:
        if a > m:
            b_a.append(a)
        else:
            c_a.append(a)
            res += a

    if not b_a:
        return res

    b_a.sort(reverse=True)
    c_a.sort()

    d += 1
    blen = len(b_a)
    bidx = (blen // d) + (1 if blen % d > 0 else 0)
    cidx = 0

    for i in range(bidx):
        res += b_a[i]

    while bidx < len(b_a):
        if blen % d == 0:
            blen2 = blen + 1
        else:
            blen2 = (blen // d + 1) * d + 1

        if cidx + blen2 - blen > len(c_a):
            break

        csum = 0
        for i in range(cidx, cidx + blen2 - blen):
            csum += c_a[i]
            cidx += 1

        if csum >= b_a[bidx]:
            break

        res += b_a[bidx] - csum
        bidx += 1
        blen = blen2

    return res


n, d, m = map(int, stdin.readline().split())
a_a = list(map(int, stdin.readline().split()))
stdout.write(str(Boboniu_Chats_with_Du(n, d, m, a_a)) + "\n")
