
def solve():
    n, k = map(int, input().split())
    pts = [int(i) for i in input().split()]
    peak = 0
    for i in range(1, len(pts), 2):
        if pts[i] > pts[i-1] and pts[i] > pts[i+1]:
            pts[i] = pts[i] - 1
            peak += 1
        if peak == k:
            break
    print(' '.join((str(j) for j in pts)))

solve()
