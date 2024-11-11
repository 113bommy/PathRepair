d, g = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(d)]
ans = 1000
for i in range(1 << d):
    score = 0
    num = 0
    rest = 0
    for j in range(d):
        if ((i >> j) & 1) == 1:
            score += pc[j][0]*100*(j+1) + pc[j][1]
            num += pc[j][0]
        else:
            rest = j
    if score < g:
        need = (g-score-1)//(100*(rest+1))+1
        if need > pc[rest][0]-1:
            continue
        else:
            num += need
    ans = min(ans, num)
print(ans)