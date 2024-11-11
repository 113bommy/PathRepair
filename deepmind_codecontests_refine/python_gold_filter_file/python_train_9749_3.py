def lcm(a, b):
    m = a*b
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a+b


n = int(input())
s = input()
points = [int(i) for i in s.split()]
points = sorted(points)

dist = []

for i in range(len(points) - 1):
    dist.append(points[i + 1] - points[i])


c = dist[0]
for i in range(1, len(dist)):
    c = lcm(c, dist[i])

ans = 0
for i in range(len(dist)):
    ans += dist[i] // c - 1

print(int(ans))


