N = int(input())
ab = [[int(i) for i in input().split()] for _ in range(N)]
cd = [[int(i) for i in input().split()] for _ in range(N)]

ab.sort(key = lambda x: x[1], reverse=True)
cd.sort()

a = 0
for c, d in cd:
    for a, b in ab:
        if a < c and b < d:
            a += 1
            ab.remove([a, b])
            break

print(a)
