n = int(input())
points = tuple(map(int, input().split()))

def calc(points, start, stop, step):
    n = len(points)
    ans = [None] * n
    ans[start] = 0
    cnt = 1
    for i in range(start + step, stop, step):
        ans[i] = ans[i - step] + abs(points[i] - points[i - step]) * cnt
        cnt += 1
    return ans

calc1 = calc(points, 0, n, 1)
calc2 = calc(points, n - 1, -1, -1)
mini, minv = -1, float('inf')
for i in range(n):
    if calc1[i] + calc2[i] < minv:
        minv = calc1[i] + calc2[i]
        mini = points[i]
print(mini)