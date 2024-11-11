from sys import exit

n, m = map(int, input().split())
l = list(map(int, input().split()))

a = [-1] * n

for i in range(m - 1):
    p = l[i + 1] - l[i]
    if p <= 0: p += n
    if a[l[i] - 1] != -1 and a[l[i] - 1] != p:
        print(-1)
        exit(0)
    a[l[i] - 1] = p

s = set(range(1, n + 1)) - set(i for i in a if i != -1)
for i in range(len(a)):
    if a[i] == -1:
        a[i] = s.pop()

if -1 in a or len(set(a)) != n:
    print(-1)
else:
    print(*a)
