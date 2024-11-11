i = lambda: map(int, input().split())
n, x, y = i()
a = sorted(i())[::-1]

if x > y:
    x, y = y, x

print(sum(a[:x])/x + sum(a[x:][:y])/y)
