from functools import reduce

k, p = map(int, input().split())
ans = []
for x in range(1, k+1):
    ans.append(int(str(x)+str(x)[::-1]))
print(reduce(lambda a, b: (a + b) % p, ans))
