digits_b = ["1110111", "0010010", "1011101", "1011011", "0111010",
            "1101011", "1101111", "1010010", "1111111", "1111011"]
counts = [s.count('1') for s in digits_b]
digits_num = [int(s, 2) for s in digits_b]

nn, kk = map(int, input().split())
poss = [[] for i in range(nn)]

for i in range(nn):
    s = input()
    count = s.count('1')
    num = int(s, 2)

    for d in range(9, -1, -1):
        if num & digits_num[d] == num:
            poss[i].append((d, counts[d] - count))


dp = [[0 for __ in range(kk+1)] for _ in range(nn+1)]
dp[0][0] = 1


for n in range(nn):
    for k in range(kk+1):
        if not dp[n][k]:
            continue

        for _, c in poss[nn-n-1]:
            if c + k > kk:
                continue

            dp[n+1][k+c] = 1

out = []

if dp[nn][kk]:
    for n in range(nn):
        for nx, c in poss[n]:
            if c > kk or not dp[nn-1-n][kk-c]:
                continue

            kk -= c
            out.append(nx)
            break

    print(''.join(map(str, out)))

else:
    print(-1)
