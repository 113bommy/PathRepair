n, m = [int(x) for x in input().split()]
rs = [input() for _ in range(n)]
mask = [1] * m
 
def get_masked(x):
    return ''.join(y for y, m in zip(x, mask) if m)
 
res = 0
for i in range(n):
    l = [get_masked(x)[:i - res + 1] for x in rs]
    if not all(l[i] <= l[i+1] for i in range(len(l)-1)):
        mask[i] = 0
        res += 1
print(res)