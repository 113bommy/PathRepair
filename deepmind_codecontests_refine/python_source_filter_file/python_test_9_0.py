from bisect import bisect_right, bisect_left, insort
def solve():
    n, m, k = map(int, input().split())
    arr = []
    for _ in range(n):
        a = list(map(int, input().split()))
        arr.append(a)
    cols = [[] for _ in range(m)]
    for i in range(n):
        for j in range(m):
            if arr[i][j] != 2:
                cols[j].append(i)
##    for c in cols:
##        print(c)
##    print()
##    for r in rows1:
##        print(r)
##    print()
##    for r in rows3:
##        print(r)
##    print()
    queries = list(map(int, input().split()))
    for startPos in queries:
        x, y = 0, startPos-1
        while x != n-1:
            if arr[x][y] == 2:
                index = bisect_right(cols[y], x)
                if index == len(cols[y]):
                    break
                else:
                    x = cols[y][index]
            elif arr[x][y] == 1:
                arr[x][y] = 2
                cols[y].remove(x)
                y += 1
            else:
                arr[x][y] = 2
                cols[y].remove(x)
                y -= 1
        print(y+1, end=" ")
solve()


