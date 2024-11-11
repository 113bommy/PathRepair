import sys
input = sys.stdin.readline

n, a, b, c = map(int, input().split())
count = {
    'A': a,
    'B': b,
    'C': c
}
queries = []
for _ in range(n):
    query = tuple(input().replace('\n', ''))
    queries.append(query)


def solve(plus, minus):
    count[plus] += 1
    count[minus] += 1
    ans.append(plus)


ans = []
for idx, (x, y) in enumerate(queries):
    if count[x] == count[y] == 0:
        print('No')
        exit()

    if count[x] == count[y] == 1:
        if idx == n-1:
            solve(x, y)
            break

        nex = queries[idx+1]
        if x in nex:
            solve(x, y)
        else:
            solve(y, x)

    elif count[x] >= count[y]:
        solve(x, y)

    else:
        solve(y, x)

print('Yes')
for c in ans:
    print(c)
