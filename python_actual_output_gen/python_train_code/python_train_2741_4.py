inp = lambda: list(map(int, input().split()))
n, m = inp()
ds = [0]*(n+1)
for num in inp():
    ds[num-1] += 1
print(min(ds))