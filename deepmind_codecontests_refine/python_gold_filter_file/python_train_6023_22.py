H, W = map(int, input().split())

S = H * W
ans = 0
if H * W % 3 != 0:
    ans = 10 ** 11
    for a, b in zip((H, W), (W, H)):
        for i in range(1, a):
            S1 = i * b
            S2 = (a - i) * (b // 2)
            S3 = S - S1 - S2
            S4 = ((a - i) // 2) * b
            S5 = S - S1 - S4

            ans = min(ans,
                      max(S1, S2, S3) - min(S1, S2, S3),
                      max(S1, S4, S5) - min(S1, S4, S5))

print(ans)
