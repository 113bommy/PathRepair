from sys import stdin
n = int(input())
z = list(map(int, stdin.readline().rstrip().split(" ")))
z.sort()
t = 1
c = 0
for i in range(n):
    if z[i] <= t:
        c+=1
    t+=z[i]
print(c)