n,k = map(int, input().split())
l = list(map(int, input().split()))
x = sorted(l)
print(sum(x[k:]))