import math

n, k = map(int, input().split())
strings = list(input().split())
a = []
MIN = -1000 * 1000 * 1000 * 1000


def prove(pos):

    index = pos
    while index < len(a):
        if a[index] != MIN:
            return False;
        index += k

    element = -((index - pos) // k - 1) // 2

    index = pos
    while index < len(a):
        a[index] = element
        element += 1
        index += k

    return True


def begin(pos):
    if a[pos] != MIN:
        return pos
    first = pos
    length = 0
    while a[first] == MIN:
        first += k
        length += 1
    element = min(a[first] - length + 1, -((first - pos) // k - 1) // 2);
    while pos < first:
        a[pos] = element
        element += 1
        pos += k

    return first


def end(pos, index):
    pos += k
    if pos == index or pos >= len(a):
        return
    element = max(a[pos - k] + 1, -((index - pos) // k - 1) // 2);
    while pos < len(a):
        a[pos] = element
        element += 1
        pos += k


def fill(l, r):
    if (r - l) // k - 1 > a[r] - a[l] - 1:
        print("Incorrect sequence")
        exit(0)
    cnt = (r - l) // k - 1

    if a[l] >= 0:
        element = a[l] + 1

    if a[r] <= 0:
        element = a[r] - cnt

    if (a[r] >= 0) and (a[l] <= 0):
        element = max(min(-(cnt // 2), a[r] - cnt), a[l] + 1)

    l += k
    while l < r:
        a[l] = element
        element += 1
        l += k


def update(pos):
    if prove(pos):
        return

    pos = begin(pos)
    index = pos + k
    while index < len(a):
        index = pos + k
        while index < len(a) and a[index] == MIN:
            index += k
        if index >= len(a):
            break
        fill(pos, index)
        pos = index

    end(pos, index)


def print_array():
    for x in a:
        print(x, end = ' ')


for x in strings:
    if x == '?':
        a.append(MIN)
    else:
        a.append(int(x))

for i in range(0, k):
    update(i)

print_array()