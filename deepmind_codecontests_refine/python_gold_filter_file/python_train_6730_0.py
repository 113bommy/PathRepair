from collections import Counter

k = int(input())
str_data = input()

fd = Counter()
for i in str_data.split():
    fd[int(i)] += 1

d_min = min(fd.keys())
d_mid = d_min + 1
d_max = max(fd.keys())

if d_max - d_min <= 1:
    print(k)
    print(str_data)
else:
    if fd[d_mid] // 2 > min(fd[d_min], fd[d_max]):
        while fd[d_mid] > 1:
            fd[d_min] += 1
            fd[d_max] += 1
            fd[d_mid] -= 2
            k -= 2
    else:
        while fd[d_min] != 0 and fd[d_max] != 0:
            fd[d_min] -= 1
            fd[d_max] -= 1
            fd[d_mid] += 2
            k -= 2

    res = ([str(d_min)] * fd[d_min] +
           [str(d_mid)] * fd[d_mid] +
           [str(d_max)] * fd[d_max])
    print(k)
    print(' '.join(res))
