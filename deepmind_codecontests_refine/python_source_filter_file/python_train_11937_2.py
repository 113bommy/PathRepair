import itertools

n = int(input())
l = [None] * 4
for _ in range(4):
    tmp = 0
    for i in range(n):
        line = input().strip()
        for j, s in enumerate(line):
            tmp += (i + j) % 2 and s == '1' or (not (i + j) % 2) and s == '0'
    l[_] = tmp
    
    if _ != 3:
        input()

min_ = 1000000
for i1, i2, i3, i4 in itertools.combinations([0, 1, 2, 3], 4):
    min_ = min(min_, l[i1] + l[i2] + n * n - l[i3] + n * n - l[i4])
print(min_)