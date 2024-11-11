n, m = list(map(int, input().split(" ")))

ds = [x for x in range(1, m**.5+1) if m%x==0]
ds = ds + [m%x for x in ds]
ds = [x for x in ds if x<=m//n]
print(max(ds))