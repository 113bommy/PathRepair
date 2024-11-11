n, m = map(int, input().split())


root = list(range(n + 1))


# from collections import defaultdict
# d = defaultdict(set)
cnt = [1] * (n + 1)


def find(i):
    if i == root[i]:
        return i
    root[i] = find(root[i])
    return root[i]

def union(u, v):
    fu, fv = find(u), find(v)
    if fu == fv:
        return
    root[max(u, v)] = min(fu, fv)
    cnt[min(fu, fv)] += cnt[max(u, v)]



for i in range(m):
    u, v = map(int, input().split())
    union(u, v)



# print(d)
print(max(cnt))
