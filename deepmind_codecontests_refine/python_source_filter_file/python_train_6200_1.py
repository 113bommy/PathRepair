n = int(input())
a = map(int, input().split())

pow2 = []
x = 1
for i in range(33):
    x <<= 1
    pow2.append(x)

ans = 0
cnt = {}
for x in a:
    for y in pow2:
        need = abs(y - x)
        if need in cnt:
            ans += cnt[need]
    cnt[x] = cnt.get(x, 0) + 1
print(ans)

