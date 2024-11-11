noe = int(input())
arr = [int(x) for x in input().split()]
cnt = [0] * int(2e5)
cur = set()
for x in arr:
    cnt[x] = len(cur)
    cur.add(x)
    print(cnt[:10], cur)
print(sum(cnt))