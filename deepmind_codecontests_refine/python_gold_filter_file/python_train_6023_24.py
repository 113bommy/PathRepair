def solve(s1, s2, s3):
    S = [s1, s2, s3]
    return(max(S) - min(S))


H, W = map(int, input().split())
S = H * W
for j in range(1, W):
    S1 = H * j
    i = H // 2
    S2 = (W - j) * i
    S3 = (W - j) * (H - i)
    S = min(S, solve(S1, S2, S3))

for i in range(1, H):
    S1 = W * i
    j = W // 2
    S2 = (H - i) * j
    S3 = (H - i) * (W - j)
    S = min(S, solve(S1, S2, S3))

S = min(S, H * (W % 3 > 0))
S = min(S, W * (H % 3 > 0))


print(S)
