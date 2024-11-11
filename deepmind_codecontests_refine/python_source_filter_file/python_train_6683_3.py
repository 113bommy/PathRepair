from collections import deque
n, k = map(int, input().split())
li = list(map(int, input().split()))
li.sort()
print(li)
dq = deque()

a = li[0]
countt = 1
distp = -1
for i in range(1, len(li)):
    if li[i] == a:
        countt += 1
    else:
        dq.append([a, countt, distp, li[i]-a])
        distp = li[i]-a
        countt = 1

    a = li[i]

dq.append([a, countt, distp, -1])
diff = li[-1]-li[0]

while k > 0 and diff > 0:
    if dq[0][1] > dq[-1][1]:  # go from top
        if k > dq[-1][2] * dq[-1][1]:
            k -= dq[-1][2] * dq[-1][1]
            x1 = dq.pop()
            x2 = dq.pop()
            dq.append([x2[0], x2[1]+x1[1], x2[2], -1])
            diff -= x1[0]-x2[0]
        else:
            diff -= k // dq[-1][1]
            k = 0
    else: # go from bot
        if k > dq[0][3] * dq[0][1]:
            k -= dq[0][3] * dq[0][1]
            x1 = dq.popleft()
            x2 = dq.popleft()
            dq.appendleft([x2[0], x2[1]+x1[1], -1, x2[3]])
            diff -= x2[0]-x1[0]
        else:
            diff -= k // dq[0][1]
            k = 0
            print("yyyyy")
    
    print(dq)
    print(f"diff:{diff} k:{k}")
print(diff)
