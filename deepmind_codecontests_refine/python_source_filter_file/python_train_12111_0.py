from sys import stdin, stdout

n, k = map(int, stdin.readline().split())
values = sorted(list(map(int, stdin.readline().split())))
d = {}

for v in values:
    if v in d:
        d[v] += 1
    else:
        d[v] = 1

ind = 0

while (k > d[values[ind]] * n):
    k -= d[values[ind]] * n

    ind += 1
    while values[ind] == values[ind - 1]:
        ind += 1


for i in range(n):
    if k - d[values[i]] <= 0:
        stdout.write(str(values[ind]) + ' ' + str(values[i]))
        k -= d[values[i]]
        break
    else:
        k -= d[values[i]]