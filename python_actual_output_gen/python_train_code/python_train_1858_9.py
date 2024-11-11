from sys import stdin

inp = stdin.readline

n, m = [int(x) for x in inp().strip().split()]

boys = [0]*n
girls = [0]*m
for x in inp().strip().split()[1:]:
    boys[int(x)] = 1
for x in inp().strip().split()[1:]:
    girls[int(x)] = 1


for x in range(max(n,m)**2):
    if boys[x%n] or boys[x%n]:
        boys[x%n] = 1
        girls[x%m] = 1


boys.sort()
girls.sort()

if not min(boys[0],girls[0]):
    print("NO")
else:
    print("YES")