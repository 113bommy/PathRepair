# キュー
from collections import deque

n = int(input())
links = [[] for _ in range(n+1)]
for i in range(1,n+1):
    ss = input()
    for j,s in enumerate(ss,1):
        if(s=='1'):
            links[i].append(j)

ans = -1
for i in range(1,n+1):
    ng_flag = False

    depth = [-1] * (n+1)
    depth[i] = 1
    max_depth = 1
    d = deque()
    d.append(i)
    while(d):
        now = d.pop()
        for j in links[now]:
            if(depth[j] == -1):
                depth[j] = depth[now] + 1
                d.append(j)
                max_depth = max(max_depth, depth[j])
            else:
                if(abs(depth[j] - depth[now]) != 1):
                    ng_flag = True
                    break
        if(ng_flag):
            break
    if(not ng_flag):
        ans = max(ans, max_depth)

print(ans)