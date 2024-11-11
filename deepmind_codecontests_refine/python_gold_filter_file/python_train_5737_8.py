
n = int(input())

single_idx = -1
segments = []
for i in range(n):
    s, e = map(int, input().split())
    segments.append((s, e))

segments.sort(key=lambda x: x[0])

left = [(0, 1000000000) for _ in range(n)]
right = [(0, 1000000000) for _ in range(n)]

top = 1000000000
bottom = 0
for i in range(n):
    s, e = segments[i]
    bottom = max(bottom, s)
    top = min(top, e)
    left[i] = (bottom, top)

top = 1000000000
bottom = 0
for i in range(n-1, -1, -1):
    s, e = segments[i]
    bottom = max(bottom, s)
    top = min(top, e)
    right[i] = (bottom, top)

best = max(left[-2][1] - left[-2][0], right[1][1] - right[1][0])
for i in range(1, n-1):
    s1, e1 = left[i-1]
    s2, e2 = right[i+1]
    s = max(s1, s2)
    e = min(e1, e2)
    best = max(best, e - s)

print(max(0, best))



