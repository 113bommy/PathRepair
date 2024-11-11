import copy

n, m = map(int, input().split())
stations = [[] for i in range(n)]
max_len = 0
for i in range(m):
    fr, to = map(int, input().split())
    stations[fr - 1].append(to - 1)
    max_len = max(max_len, len(stations[fr - 1]))
max_go = 1000000

for i in range(n):
    stations[i].sort(key=lambda x:((x - i) % n))

go = (max(max_len - 2, 0)) * n
for i in range(n):
    l = max(0, len(stations[i]) - max_len + 2)
    if l == 0:
        stations[i] = []
    else:
        stations[i] = stations[i][0:l]

for station in range(n):
    st = copy.deepcopy(stations)
    to_go = 0
    counter = 0
    train = set()
    for i in range(station, n*3):
        counter += 1
        i = i % n
        if i in train:
            train.remove(i)
            if not train:
                to_go = counter
        if len(st[i]) != 0:
            train.add(st[i][-1])
            st[i].pop()
    print(go + to_go - 1, end=" ")





