from collections import defaultdict
import sys 

input = sys.stdin.buffer.readline

def find(pas, x):
    if pas[x] != x:
        pas[x] = find(pas, pas[x])
    return pas[x] 

def union(pas, x, y):
    fx, fy = find(pas, x), find(pas, y)
    if fx != fy:
        pas[fx] = fy 
    return

def work(n, k, points, row, col, explosion_time):
    pas = list(range(n))

    for x in row:
        ps = []
        for i in row[x]:
            px, py = points[i]
            ps.append([py, px, i])

        ps.sort()
        for i in range(len(ps) - 1):
            dist = abs(ps[i][0] - ps[i + 1][0])
            if dist <= k:
                union(pas, ps[i][2], ps[i + 1][2])

    for y in col:
        ps = []
        for i in col[y]:
            px, py = points[i]
            ps.append([px, py, i])
        ps.sort()
        for i in range(len(ps) - 1):
            dist = abs(ps[i][0] - ps[i + 1][0])
            if dist <= k:
                union(pas, ps[i][2], ps[i + 1][2])
    
    mint = defaultdict(int)
    for i in range(n):
        fi = find(pas, i)
        time = explosion_time[i]
        if fi not in mint:
            mint[fi] = time 
        else:
            mint[fi] = min(mint[fi], time)
    nodes = []
    for fa, time in mint.items():
        nodes.append([time, fa])
    nodes.sort()
    ans = 0 
    nodes.pop()
    while nodes:
        time, fa = nodes.pop()
        if fa > ans:
            ans += 1 
    return ans 


def main():
    test = int(input())

    for _ in range(test):
        _ = input()
        n, k = map(int, input().split())
        points = defaultdict(list)
        row, col = defaultdict(list), defaultdict(list)
        explosion_time = defaultdict(int)

        for i in range(n):
            x, y, t = map(int, input().split())
            points[i] = [x, y]
            row[x].append(i)
            col[y].append(i)
            explosion_time[i] = t 
        
        res = work(n, k, points, row, col, explosion_time)
        print(res)
    
    return 
if __name__ == "__main__":
    main()

