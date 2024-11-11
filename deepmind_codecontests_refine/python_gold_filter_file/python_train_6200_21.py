n = int(input())
A = list(map(int, input().split()))
cnt = {}

for a in A:
    if a in cnt:
        cnt[a] += 1
    else:
        cnt[a] = 1

c = 0
for a in A:
    cnt[a] -= 1
    for n in range(1, 32):
        cur = 2**n
        if cur <= a:
            continue
        if cur - a in cnt:
            c += cnt[cur - a]

print(c)
