n, k, s = map(int, input().split())
A = [s]*k
if s == pow(10, 9):
    A += [1]*(n-k)
else:
    A += [s-1]*(n-k)
print(*A)