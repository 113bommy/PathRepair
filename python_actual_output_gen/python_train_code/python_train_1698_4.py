t = int(input())
for _ in range(t):
    n,c0,c1,h = [int(x) for x in input().split()]
    s = list(input())
    x1 = s.count('1')
    x0 = s.count('0')
    a = c0*x0+c1*x1
    a = min(a,c0*x0+h*x1,c1*x1+h*x0)
    print(a)
            