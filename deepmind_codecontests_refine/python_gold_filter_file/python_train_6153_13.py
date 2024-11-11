def cross(p1, p2, p):
    return (p2[0] - p1[0]) * (p[1] - p1[1]) - (p[0] - p1[0]) * (p2[1] - p1[1])


n, d = map(int, input().split())
m = eval(input())
p1 = [0, d]
p2 = [d, 0]
p3 = [n, n - d]
p4 = [n - d, n]

for i in range(m):
    px = [int(x) for x in input().split()]
    if (cross(p1, p2, px) * cross(p3, p4, px) >= 0 and cross(p2, p3, px) * cross(p4, p1, px) >= 0):
        print("YES")
    else:
        print("NO")
