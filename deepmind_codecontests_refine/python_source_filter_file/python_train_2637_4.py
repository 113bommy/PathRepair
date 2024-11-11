sz = int(input())
cnt = [0]*5
for i in input().split():
    cnt[int(i)] += 1
res = cnt[4] + cnt[3]
if cnt[3]>= cnt[1]:
    cnt[1] = 0
else:
    cnt[1] -= cnt[3]
res += cnt[2]//2
cnt[2] %= 2
if cnt[1]!=0:
    if cnt[2]!=0:
        res += 1
        cnt[1] = cnt[1]-2 if cnt[2]>=2 else 0
else:
    res += cnt[2]
res += cnt[1]//4 if cnt[1]%4 ==0 else cnt[1]//4 + 1
print(res)