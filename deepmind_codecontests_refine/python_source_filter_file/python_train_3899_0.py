n, v = map(int, input().split())

lst = [0] * 3002
for _ in range(n):
    a, b = map(int, input().split())
    lst[a] += b

b = lst[:]
t = 0


for day in range(3001):
    x = min(v, b[day])
    t += x
    b[day+1] += min(b[day]-x, lst[day])

print(t)




