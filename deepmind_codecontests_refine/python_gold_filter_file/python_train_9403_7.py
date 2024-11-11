from sys import stdin

l = list(map(int, stdin.read().split()))
n, k = l[0], l[1]
l = l[2:n+2]
l.sort()

q = max(l[n-k], 1)

print(sum(1 for x in l if x >= q))