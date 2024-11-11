n, k = map(int, input().strip().split())
a = [int(s) for s in input().strip().split()]

r = max(0, 2*k*n - 2*sum(a) - n)

print(r)
