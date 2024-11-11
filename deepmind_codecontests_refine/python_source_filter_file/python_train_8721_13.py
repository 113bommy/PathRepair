n, m = map(int, input().split())
a = list(map(int, input().split()))
print("Yes" if len([i for i in a if i/sum(a) >= 1/(4 * m)]) >= n else "No")