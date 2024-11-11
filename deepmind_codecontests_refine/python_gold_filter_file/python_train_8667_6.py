n = int(input())
l = list(map(int,input().split()))
q = int(input())
cnt = {}
for i in range(1,10**5+1):
    cnt[i] = 0

cnt2 = 0
cnt4 = 0
#print(cnt)
for x in l:
    cnt2 -= cnt[x]//2
    cnt4 -= cnt[x]//4
    cnt[x] += 1
    cnt2 += cnt[x] // 2
    cnt4 += cnt[x] // 4

#print(cnt)
for _ in range(q):
    s = input()
    e1 = s[0]
    e2 = int(s[2:])
    cnt2 -= cnt[e2] // 2
    cnt4 -= cnt[e2] // 4
    if e1 == "+":
        cnt[e2] += 1

    else:
        cnt[e2] -= 1

    cnt2 += cnt[e2] // 2
    cnt4 += cnt[e2] // 4
    if cnt2 >= 4 and cnt4 >= 1:
        print("YES")

    else:
        print("NO")