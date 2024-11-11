dl = []
n = int(input())
sum_r = []
sum_c = []
l = []
count = 0
for k in range(n):
    l = list(map(int,input().split()))
    dl.append(l)
if n == 1:
    print(0)
else:
    for i in range(n):
        sum_r.append(sum(dl[i]))
    for i in range(n):
        s = 0
        for j in range(n):
            s = s + dl[j][i]
        sum_c.append(s)
    maxx = max(sum_c)
    mini = min(sum_r)
    e = sum_c.index(maxx)
    r = sum_r.index(mini)
    for i in range(n):
        for j in range(n):
            if sum_r[i] > sum_c[j]:
                count = count + 1
    print(count)