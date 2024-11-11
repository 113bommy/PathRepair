from sys import stdin, stdout


def right_range(x):
    return cntr[-1] - cntr[x] - (coordinate[x] - coordinate[0]) * (n - x - 1)


def left_range(x):
    return cntl[0] - cntl[x] - (coordinate[-1] - coordinate[x]) * x


n = int(stdin.readline())
coordinate = list(map(int, stdin.readline().split()))
cntr = [0]
cntl = [0]
for i in range(1, n):
    cntr.append(cntr[-1] + coordinate[i] - coordinate[0])
for i in range(n - 2, -1, -1):
    cntl.append(cntl[-1] + coordinate[-1] - coordinate[i])
cntl = cntl[::-1]
ind = 0
for i in range(n):
    if right_range(ind) + left_range(ind) > right_range(i) + left_range(i):
        ind = i
print(coordinate[ind])