mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    if N == 2:
        if A[0] == A[1]:
            print(0)
        elif A[0] < A[1]:
            print(-1)
        else:
            if (A[0] - A[1]) %2 == 0:
                print((A[0] -  A[1])//2)
            else:
                print(-1)
        exit()

    g1 = A[0]
    g2 = A[1]
    g3 = 0
    for i in range(2, N):
        g3 ^= A[i]
    n1 = g1.bit_length()
    n2 = g2.bit_length()
    n3 = g3.bit_length()
    NN = max(n1, n2, n3)
    ans = 0
    cnt = 0
    while True:
        cnt += 1
        if cnt == 10000:
            print(-1)
            exit()
        for i in range(NN):
            if (g1 >> i & 1) ^ (g2 >> i & 1) != (g3 >> i & 1):
                r1 = g1 % (1 << i) + 1
                r2 = (1<<i) - g2 % (1 << i)
                if r1 < r2:
                    g1 -= r1
                    g2 += r1
                    ans += r1
                    break
                elif r1 > r2:
                    g1 -= r2
                    g2 += r2
                    ans += r2
                    break
                else:
                    print(-1)
                    exit()
            if g1 ^ g2 == g3:
                if ans != A[0]:
                    print(ans)
                else:
                    print(-1)
                exit()


if __name__ == '__main__':
    main()
