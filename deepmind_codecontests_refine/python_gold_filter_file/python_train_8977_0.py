import sys

max_int = 1000000001  # 10^9+1
min_int = -max_int

pows = []
for i in range(1, 62):
    pows.append(2 ** i)

t = int(input())
for _t in range(t):
    n = int(sys.stdin.readline())

    ans = 0
    for number, one in enumerate(pows, 1):
        # print(n, one)
        if n - one // 2 < 0:
            break
        ans += number * (1 + (n - one // 2) // one)
        # print(ans)

    # #ans = 0
    # for i in range(1, n+1):
    #     # ans += pows[i ^ i-1]
    #     print(pows[i ^ i-1])

    # print(ans)
    print(ans)
    # print()
