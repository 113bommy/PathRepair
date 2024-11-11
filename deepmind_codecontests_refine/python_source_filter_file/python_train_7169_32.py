n = int(input())
for i in range(n):
    p = list(map(float, input().split()))
    print("YES" if abs((p[3] - p[1]) * (p[2] - p[0]) - (p[7] - p[5]) * (p[6] - p[4])) < 1e-10 else "NO")