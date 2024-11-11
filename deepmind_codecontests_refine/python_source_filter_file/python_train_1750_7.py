H, W, N = map(int, input().split())
sr, sc = map(int, input().split())
S = list(input())
T = list(input())

# 青木くんが左に動かせるということは、駒の生存可能範囲の右端を1つのばせる
# 高橋くんが左に動かせるということは、駒の生存可能範囲の左端を1つ縮める
l = 1
r = W
u = 1
d = H
for s, t in zip(S[::-1], T[::-1]):
    if t in ('L', 'R'):
        if t == 'L':
            r = min(r + 1, W)
        else:
            l = max(1, l - 1)
    else:
        if t == 'U':
            d = max(d + 1, H)
        else:
            u = min(u - 1, 1)

    if s in ('L', 'R'):
        if s == 'L':
            l += 1
        else:
            r -= 1
    else:
        if s == 'U':
            u += 1
        else:
            d -= 1
    if l > r or u > d:
        print('NO')
        exit()

if l <= sc <= r and u <= sr <= d:
    print('YES')
else:
    print('NO')
