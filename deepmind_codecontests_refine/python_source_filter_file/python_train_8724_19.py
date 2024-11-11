n, m = map(int, input().split())
s = {*range(1, m+1)}
for _ in range(n):
    k, *a = map(int, input().split())
    s &= set(a)
print(len(s))