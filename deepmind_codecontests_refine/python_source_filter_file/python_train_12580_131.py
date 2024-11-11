n,k = map(int, input().split())
l = map(int, input().split())
x = sorted(l)
print(sum(x[k:]))
