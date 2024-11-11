from sys import stdin
n = int(input())
l = list(map(int, stdin.readline().rstrip().split(" ")))

m = l[0]
for i in range(1, n):
    x = min(l[0], l[i])
    t = x//i
    z = x//max(n-i,i)
    m = min(m, min(t, z))
print(m)