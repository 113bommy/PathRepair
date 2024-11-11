# from : https://atcoder.jp/contests/yahoo-procon2019-qual/submissions/4212377
H,W = map(int, input().split())
A = [ [int(j) for j in input().split()] for _ in range(H)]
MOD = 998244353

piv = 0

# Gaussian Elimination to calculate rank of the matrix A
for w in range(W): # fix column, 
    r = -1
    for h in range(piv, H):
        if A[h][w] == 1:
            r = h
            break
    if r == -1: # there is no odd cell for all the rows inside intersections.
        continue 

    # You want to set ODD ROW ( A[h][w] == 1 ) into pivot row.
    if r != piv: # already, skip.
        for j in range(W): # swap rows
            A[r][j], A[piv][j] = A[piv][j], A[r][j]

    # for h in 
    for h in range(H):
        if h != piv and A[h][w] == 1: # really needed?
            # for j in range(W):
            for k in range(h, W):
                A[h][k] ^= A[piv][k]
                # A[h][j] ^= A[piv][j] # for other rows, erase ...
                # Hakidashi method: http://senkei.nomaki.jp/gaussian_elimination.html
                # https://ja.wikipedia.org/wiki/%E3%82%AC%E3%82%A6%E3%82%B9%E3%81%AE%E6%B6%88%E5%8E%BB%E6%B3%95 : Gaussian Elimination
    piv += 1


# print("----output matrix ----")
# for h in range(H):
#     print(A[h])
# exit(0)


# from pprint import pprint; pprint(A)

ret = 1
ret = pow(2, H, MOD)
# for h in range(H):
#     ret = ret * 2 % MOD

sub = 1
# for i in range(H-piv):
#     sub = sub * 2 % MOD
sub = pow(2, H-piv, MOD)


ret += MOD - sub          # ret = 2^N - 2^(N-r)
ret %= MOD

for i in range(W-1):      # ret *= 2^(M-1)
    ret = ret * 2 % MOD

# from editorial  : https://img.atcoder.jp/yahoo-procon2019-qual/editorial.pdf
# rank : r 
# 2^(N+M-1) - 2^(N+M-r-1)

print(ret % MOD) 