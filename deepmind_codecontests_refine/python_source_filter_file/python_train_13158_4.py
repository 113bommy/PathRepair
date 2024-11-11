n, k = map(int, input().split())
a = list(map(int, input().split()))+[0]

forward = [0]*n
backward = [0]*n

sm = sum(a[:k])
mx = sm
for i in range(1+n-2*k):
    mx = max(mx, sm)
    forward[i] = mx
    sm -= a[i]
    sm += a[i+k+1]
    
sm = sum(a[n-k:])
ind = n-k+1
mx = sm
for i in range(n-k, k-1, -1):
    if sm >= mx:
        mx = sm
        ind = i+1
    backward[i] = (ind, mx)
    sm += a[i-1]
    sm -= a[i+k-1]

ans = [0, 0]
ans_sm = 0
for i in range(1+n-2*k):
    if forward[i]+backward[k+i][1] > ans_sm:
        ans_sm = forward[i]+backward[k+i][1]
        ans = [i+1, backward[k+i][0]]

print(*ans)