h,w,k = map(int,input().split())
s = [input() for _ in range(h)]
ans = [[0]*w for _ in range(h)]

num = 1
start = -1
for i,si in enumerate(s):
    count = 0
    if "#" in si:
        if start<0:start = i
        for j,sij in enumerate(si):
            if sij == "#":
                count += 1
                if count >= 2: num += 1
            ans[i][j] = num
        num += 1
    elif start>0:
        for j in range(w):
            ans[i][j] = ans[i-1][j]

for i in range(start,0,-1):
    for j in range(w):
        ans[i-1][j] = ans[i][j]

for i in range(h):
    print(*ans[i])