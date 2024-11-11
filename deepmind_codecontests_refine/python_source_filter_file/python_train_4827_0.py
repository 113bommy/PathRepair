n=input()
lst = list(map(float, input().split()))

ds = []
ds.append(0)

for i, elem in enumerate(lst[1:]):
    ds.append(ds[i] * elem + lst[i-1]*elem)

ans = 2 * sum(ds) + sum(lst)
print(ans)
