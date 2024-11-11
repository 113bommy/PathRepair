from collections import deque

n, k = map(int, input().split())
p = list(map(int, input().split()))
c = list(map(int, input().split()))

ans = -1000000000
for i in range(n):
    now = i
    j = 0
    score = deque([0])
    while j < k:
        score.append(score[j] +c[p[now]-1])
        now = p[now]-1
        j += 1
        if now == i:
            break
    ans = max(ans, max(list(score)[1:]))
    if j < k and score[-1] > 0:
        loop_num = k//j
        rest = k%j
        ans = max(ans, max(list(score)[:rest+1])+loop_num*score[-1] )
        ans = max(ans, max(list(score))+(loop_num-1)*score[-1] )
print(ans)
        