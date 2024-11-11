import queue

def solve(w, h):
    q = queue.Queue()
    m = [['#' for i in range(w+2)] for j in range(h+2)]
    for i in range(h):
        inp = input()
        for j in range(w):
            m[i+1][j+1] = inp[j]
            if m[i+1][j+1] == '@':
                start = [i+1,j+1]
    q.put(start)
    c = 1
    while not q.empty():
        cur = q.get()
        XY = [(1,0), (-1, 0), (0, 1), (0, -1)]
        for x, y in XY:
            cx = cur[0]+x
            cy = cur[1]+y
            if m[cx][cy] == '.':
                m[cx][cy] = '#'
                q.put([cx, cy])
                c+=1
    return c

while True:
    w, h = [int(i) for i in input().split()]
    if w == 0 and h == 0:
        break
    print(solve(w,h))