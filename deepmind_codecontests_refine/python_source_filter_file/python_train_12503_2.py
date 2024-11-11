from bisect import bisect_left

sum = [0]*200005
srt = []
n,t = map(int,input().split())
a = list(map(int,input().split()))

tree = [0]*200005

def get(x):
    ans = 0
    while x:
        ans += tree[x]
        x -= x&-x
    return ans

def update(x):

    while x <= 200002:
        tree[x] += 1
        x += x&-x


for i in range(n):
    if i:
        sum[i] = sum[i-1] + a[i]
    else:
        sum[i] = a[i]
    srt.append(sum[i])

if 0 not in srt:
    srt.append(0)

srt.sort()

ans = 0
update(bisect_left(srt,0) + 1)




for i in range(n):
    l = min(n-1,bisect_left(srt,sum[i] - t))

    if srt[l] <= sum[i] - t:
        l = l+1

    cnt = get(l)
    ans += i + 1 - cnt


    update(bisect_left(srt,sum[i]) + 1)

print(ans)

