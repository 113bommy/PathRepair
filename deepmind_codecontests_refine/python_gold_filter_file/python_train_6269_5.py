n, m = map(int, input().split(" "))

adj_list = [set() for i in range(n + 1)]
adj_count = [0] * (n + 1)

for i in range(m):
    a, b = map(int, input().split(" "))
    adj_list[a].add(b)
    adj_count[a] += 1
    adj_list[b].add(a)
    adj_count[b] += 1

count = 0
while True:
    r = []
    for i in range(1, n + 1):
        if adj_count[i] == 1:
            r.append(i)
    if len(r) == 0:
        break
    for i in r:
        adj_count[i] = 0
        for x in adj_list[i]:
            adj_count[x] -= 1
            adj_list[x].remove(i)
        adj_list[i].clear()
    count += 1
print(count)
