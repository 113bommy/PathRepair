from collections import deque

n = int(input())
a = list(map(int,input().split()))

p = [0] * (n-1)
m = [0] * (n-1)

for i in range(n-1):
    x,y = a[i:i+2]
    cnt = 0
    if(x > y):
        while(x>y):
            y *= 4
            cnt += 2
    else:
        x *= 4
        while(x<=y):
            x*=4
            cnt -= 2
    p[i] = cnt

for i in range(n-1):
    x,y = a[i:i+2]
    cnt = 0
    if(x < y):
        while(x<y):
            x *= 4
            cnt += 2
    else:
        y *= 4
        while(x>=y):
            y*=4
            cnt -= 2
    m[i] = cnt

cumsum_p = [0] * (n+1)
cumsum_m = [0] * (n+1)

d = deque()
for i in range(n-2,-1,-1):
    cumsum_p[i] = cumsum_p[i+1]
    if(p[i] < 0):
        d.appendleft((i,p[i]))
    elif(p[i] > 0):
        cnt = p[i]
        while(d):
            j,rem_j = d.popleft()
            if(cnt + rem_j <= 0):
                cumsum_p[i] += (j-i) * cnt
                if(cnt + rem_j < 0):
                    d.appendleft((j,cnt + rem_j))
                cnt = 0
                break
            else:
                cumsum_p[i] += (j-i-1) * (-1 * rem_j)
                cnt = cnt + rem_j
        cumsum_p[i] += (n-i-1) * cnt

d = deque()
cumsum_m[1] = 1
for i in range(n-1):
    cumsum_m[i+2] = cumsum_m[i+1] + 1
    if(m[i] < 0):
        d.appendleft((i,m[i]))
    elif(m[i] > 0):
        cnt = m[i]
        while(d):
            j,rem_j = d.popleft()
            if( cnt + rem_j <= 0 ):
                cumsum_m[i+2] += (i-j) * cnt
                if( cnt + rem_j < 0):
                    d.appendleft((j,cnt + rem_j))
                cnt = 0
                break
            else:
                cumsum_m[i+2] += (j-i) * (-1*rem_j)
                cnt = cnt + rem_j
        cumsum_m[i+2] += (i+1) * cnt

ans = cumsum_p[0]
for i in range(n+1):
    ans = min(ans, cumsum_p[i] + cumsum_m[i])

print(ans)