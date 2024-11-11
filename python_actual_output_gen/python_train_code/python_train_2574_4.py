# number of potato, height, smashed per second
n, h, k = map(int, input().split())
A = list(map(int, input().split()))

ans = 0
cur_h = 0

for x in A:
    print("x: {} cur_h: {} ans: {}".format(x, cur_h, ans))
    if cur_h + x <= h:
        cur_h += x
    else:
        ans += 1
        cur_h = x
    ans += cur_h // k
    cur_h %= k

ans += cur_h // k
cur_h %= k
ans += cur_h > 0
print(ans)
