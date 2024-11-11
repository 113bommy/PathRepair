n,p = map(int,input().split())
s = input()
ans = 0
if p == 2 or p == 5:
    for i,c in enumerate(s,1):
        if int(c)%p == 0: ans += i
else:
    cnt = [0]*p
    cnt[0] = 1
    x = 0
    d = 1
    for c in s[::-1]:
        x += d*int(c)
        x %= p
        cnt[x%p] += 1
        d *= 10
        d %= p
    # print(cnt)
    for v in cnt: ans += v*(v-1)//2
print(ans)