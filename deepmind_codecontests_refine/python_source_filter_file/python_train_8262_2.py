n, calls = int(input()), list(map(int, input().split()))

res = 0
for x in set(calls):
    if calls.count(x) == 2 and x != 0:
        res += 1
    if calls.count(x) == 3 and x != 0:
        res = -1
        break

print(res)
