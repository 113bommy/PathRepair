def dist(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

def ddist(a):
    res = 0.0
    for i in range(3):
        res += dist(a[i][0], a[i][1], a[i + 1][0], a[i + 1][1])
    return res;

n, m = map(int, input().split())
if (n == 0):
    print("0 1")
    print("0", m)
    print(0, 0)
    print(0, m - 1)
elif (m == 0):
    print(1, 0)
    print(n, 0)
    print(0, 0)
    print(n - 1, 0)
else:
    aa = [[[n - 1, m], [0, 0], [n, m], [1, 0]], [[0, 1], [n, m], [0, 0], [n, m - 1]], [[0, 0], [n, m], [0, m], [n, 0]], [[n, m], [0, 0], [0, m], [n, 0]]]
    a = max(aa, key = ddist)
    for i in a:
        print(i[0], i[1])
    
