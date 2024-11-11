n = int(input())
INF = float('inf')
p1, p2 = 0, INF
for i in range(n):
    q1, q2 = map(int, input().split())
    p1 = max(p1, q1)
    p2 = min(p2, q2)

m = int(input())
c1, c2 = 0, INF
for i in range(m):
    q1, q2 = map(int, input().split())
    c1 = max(c1, q1)
    c2 = min(c2, q2)

print(max(0, max(c1 - p2, p1 - c2)))


