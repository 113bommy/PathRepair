##n = int(input())
##a = list(map(int, input().split()))
##print(' '.join(map(str, res)))

n = int(input())
s = [i for i in range(n+2)]
p = [1 for i in range(n+2)]

p[1] = 1
p[2] = 1
x = 2
while x <= n+1:
    while x <= n+1 and p[x] == 2:
        x += 1
    y = 2
    while y*x <= n+1:
        p[y*x] = 2
        y += 1
    x += 1

res = p[2:]
m = 1
for i in range(len(res)):
    m = max(m, res[i])
print(m)
print(' '.join(map(str, res)))
