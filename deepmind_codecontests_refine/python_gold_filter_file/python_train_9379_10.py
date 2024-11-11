def intersect(a, b):
    return max(a[0], b[0]), max(a[1], b[1]), min(a[2], b[2]), min(a[3], b[3])


def nonempty(a):
    return a[0] <= a[2] and a[1] <= a[3]


_min = -1_000_000_000
_max = 1_000_000_000

n = int(input())
rectangles = []
for i in range(n):
    left, bottom, right, top = map(int, input().split())
    rectangles.append((left, bottom, right, top))

pre = [(_min, _min, _max, _max)]
for rectangle_i in rectangles[:-1]:
    pre.append(intersect(pre[-1], rectangle_i))

suf = [(_min, _min, _max, _max)]
for rectangle_i in rectangles[:0:-1]:
    suf.append(intersect(suf[-1], rectangle_i))
suf.reverse()

for i in range(n):
    without_ith_rectangle = intersect(suf[i], pre[i])
    if nonempty(without_ith_rectangle):
        print(without_ith_rectangle[0], without_ith_rectangle[1])
        break
