def rotate(i, j):    
    x, y, p, q = a[i] 
    for k in range(1, j+1):
        x, y = p - (y - q), q + (x - p)
    c[i] = x, y

def dist(i, j):
    x, y = c[i]
    p, q = c[j]
    return (x - p) ** 2 + (y - q) ** 2

def check(move):
    for i in range(4):      
        rotate(i, move[i])
    p = [1,2,3] 
    p.sort(key = lambda x: dist(0, x))
    d = [dist(0, x) for x in p]
    if d[0] == d[1] == d[2] / 2 and d[2] > 0:
        return True if dist(p[0], p[1]) == d[2] else False
    else:
        return False

n = int(input())
a = [0] * 4
c = [0] * 4
for i in range(n):
    a[0] = list(map(int, input().split()))
    a[1] = list(map(int, input().split()))
    a[2] = list(map(int, input().split()))
    a[3] = list(map(int, input().split()))
    ans = 17
    for k in range(4):
        for l in range(4):
            for p in range(4):
                for q in range(4):
                    if k + l + p + q < ans and check([k, l, p, q]):
                        ans = k + l + p + q
    print(ans if ans != 17 else -1)
