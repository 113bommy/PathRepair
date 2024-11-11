def f(x,d):
    if d%(x+1) == 0:
        return x + d//(x+1)
    return x + d//(x+1) + 1
t = int(input())

for _ in [0]*t:
    n,d = map(int,input().split())
    if d <= n:
        print('YES')
    else:
        judge = False

        for x in range(10000):
            if f(x,d) <= n:
                judge = True
                break

        if judge:
            print('YES')
        else:
            print('NO')