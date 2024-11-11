#最小コストソート

n = int(input())
a = list(map(int, input().split()))
b = sorted(a)
c = 0
for i in range(n-1):
    t = cnt = 0
    #本来i番目にいるべき値はaではどこにいるのか（ループの最小値）
    x = a.index(b[i])
    #もしあるべき場所にあったり、あるべき場所に帰ってきたら終了
    while x != i:
        #ループで最も小さい値を使いまわしながら整えていく
        #ループの最小値が入っている場所にいるべき値がaでは何処にいるか
        y = a.index(b[x])
        #a[x]とa[y]を入れ替えればよい
        a[x],a[y] = a[y],a[x];cnt += 1
        t += a[x] + a[i]
        x = y
    if cnt: c += min(t, (b[i]+b[0])*2 + t -(b[i]-b[0])*cnt)
print(c)
# print(a)
