def int_multiple():
    return  [int(c) for c in input().split()]

def int_single():
    return int(input())

def str_multiple():
    return [c for c in input().split()]

def str_single():
    return input()

# start

n, k = int_multiple()
l = int_multiple()

l = sorted(l)


costs = []
for i in range(51):
    costs.append([])

for i in range(n):
    tmp = l[i]
    cnt = 0
    while (tmp != 0):
        costs[tmp].append(cnt)
        tmp = int(tmp/2)
        cnt += 1

for val in costs[1]:
    costs[0].append(val+1)


min_cost = 9999999999999
for c in costs:
    if len(c) >= k:
        cost = sum(c[:k])
        if (cost < min_cost):
            min_cost = cost

for cc in costs:
    print(cc)

print(min_cost)
