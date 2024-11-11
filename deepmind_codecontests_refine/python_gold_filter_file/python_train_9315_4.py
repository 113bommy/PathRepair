'''
https://codeforces.com/contest/540/problem/C
Comment
'''
import sys, queue

def FILE_IO():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
'''____________________________________________________________________________________________'''

dirt = [(0, -1), (-1, 0), (0, 1), (1, 0)]
grp = []
m = n = None

def canGo(x, y):
    if x < 0 or x >= m or y < 0 or y >= n:
        return False
    return True

def bfs(r1, c1, r2, c2):
    q = queue.Queue()
    q.put([r1, c1])

    while not q.empty():
        ux, uy = q.get()

        for x, y in dirt:
            vx, vy = ux + x, uy + y

            if canGo(vx, vy):
                if grp[vx][vy] == 'X':
                    if vx == r2 and vy == c2:
                        return 'YES'
                else:
                    q.put([vx, vy])
                    grp[vx][vy] = 'X'

    return 'NO'

if __name__ == '__main__':
    #FILE_IO()
    m, n = map(int, input().split())
    grp = [None]*m

    for i in range(m):
        grp[i] = list(input())

    r1, c1 = map(int, input().split())
    r2, c2 = map(int, input().split())

    print(bfs(r1 - 1, c1 - 1, r2 - 1, c2 - 1))