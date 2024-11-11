n, m, k = map(int, input().split())
a = list(map(int, input().split()))

x = sorted(sorted(range(1,n+1), key=lambda i: a[i-1], reverse=True)[:m*k])
print(sum(a[i-1] for i in x))
print(*x[m::m])