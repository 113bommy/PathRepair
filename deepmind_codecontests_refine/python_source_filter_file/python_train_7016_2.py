class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def _input():
    N = 8
    point_sets = []
    for i in range(0, N):
        x, y = map(int, input().split())
        point_sets.append(point(x, y))
    return point_sets

def eight_point_sets(point_sets):
    t = point_sets[:]
    t.sort(key=lambda a: a.x)
    t[0:3] = sorted(t[0:3], key=lambda a: a.y)
    t[3:5] = sorted(t[3:5], key=lambda a: a.y)
    t[5:] = sorted(t[5:], key=lambda a: a.y)
    #chec x order
    for i in range(0, 4, 3):
        if t[i].x > t[i + 3].x:
            return -1
    # chec y order
    for i in range(0, 2):
        if t[i].y > t[i + 1].y:
            return -1
    # check x
    for i in range(0, 2):
        if t[i].x != t[i + 1].x:
            return -1
    if t[3].x != t[4].x:
        return -1
    for i in range(5, 7):
        if t[i].x != t[i + 1].x:
            return -1
    # check y
    for i in range(0, 3):
        if t[i].y != t[i + 5].y:
            return -1
    if t[3].y != t[0].y:
        return -1
    if t[4].y != t[2].y:
        return -1

    return 0

if __name__ == "__main__":
    point_sets = _input()
    ret = eight_point_sets(point_sets)
    if ret == 0:
        print("respectable")
    else:
        print("ugly")


