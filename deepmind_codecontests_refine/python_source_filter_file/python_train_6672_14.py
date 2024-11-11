n = int(input())
l = []
for i in range(n):
    x, y = [int(i) for i in input().split(" ")]
    l.append(sorted([x, y]))
m = [l[0][1]]
c = 1
for i in range(1, n):
    if l[i][0] <= m[-1]:
        m.append(l[i][0])
    elif l[i][1] <= m[-1]:
        m.append(l[i][1])
    else:
        print("NO")
        c = 0
        break
if c:
    print("YES")
