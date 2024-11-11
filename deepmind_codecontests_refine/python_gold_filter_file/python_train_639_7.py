n, m, k = map(int, input().split())
p = list(map(int, input().split()))
c = 0
tmp = 0
ops = 0
curr_page = (p[0] - 1) // k
for pp in p:
    if curr_page != (pp - 1 - c) // k:
        c += tmp
        tmp = 1
        ops += 1
        curr_page = (pp - 1 - c) // k
    else:
        tmp += 1
print(ops + 1)

