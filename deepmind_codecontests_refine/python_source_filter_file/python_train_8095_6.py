n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]
f0 = sorted([x+y for x, y in xy])
f1 = sorted([x-y for x, y in xy])
print(max(f0[-1]+f1[0], f0[0]+f1[-1]))