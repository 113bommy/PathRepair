def f(a,b):
    if a*b > 0:
        return -1
    return 1
t = int(input())
r = []
for i in range(0, t):
    n = int(input())
    a = list(map(int, input().split(" ")))
    for j in range(0, int(n/2)):
        b = int(a[j])
        #print('b', b)
        a[j] *= f(a[j], a[n-1-j]) * a[n-1-j]
        #print('a', a[j])
        a[n-1-j] *= -1 * f(a[j], a[n-1-j]) * b
    #print(*a)
    r.append(a)
for i in r:
    print(*i)
