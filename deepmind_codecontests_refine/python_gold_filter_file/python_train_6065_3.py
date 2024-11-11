n = int(input())
l = list(map(int, input().split()))
a = sorted(l)
c = 0
for i in range(1, n+1):
    if i in a:
        c += 1

print(n-c)
