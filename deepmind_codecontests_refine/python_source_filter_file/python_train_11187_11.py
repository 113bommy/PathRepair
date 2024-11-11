n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(sorted(([val, ind] for ind, val in enumerate(a,1)), reverse=True))
t = 0
li = []
minm = b[0][0] - b[-1][0] + 100
for i in range(k):
    diff = b[0][0] - b[-1][0]
    if diff > 0 and diff <= minm:
        t += 1
        b[0][0] -= 1
        b[-1][0] += 1
        li.append([b[0][1], b[-1][1]])
        first = b[0]
        last = b[-1]
        b.sort(reverse=True)
        if minm == b[0][0] - b[-1][0] and b[0][1] == last[1] and b[-1][1] == first[1]:
            t -= 1
            li.pop()
            break
        minm = b[0][0] - b[-1][0]

    else:
        break
print(minm, t)
for x in li:
    print(*x)