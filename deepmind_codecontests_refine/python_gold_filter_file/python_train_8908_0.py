n = int(input())
x = list(map(float, input().split()))
v = list(map(float, input().split()))
def f(x0):
    global x
    global v
    global n
    d = 0
    for i in range(n):
        d = max(d, abs(x0 - x[i]) / v[i])
    return d
l = 0
r = max(x)+ 10
for i in range(85):
    m1 = (l + l + r) / 3
    m2 = (l + r + r) / 3
    if (f(m1) > f(m2)):
        l = m1
    else:
        r = m2
#print(l)
print(f(l))
