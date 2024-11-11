def solve():
    x,n,m=[int(v) for v in input().split()]
    while (n>0 or m>0) and x>0:
        if n and x//2+10 < x:
            x=x//2+10
            n-=1
        elif m>0:
            x-=10
            m-=1
        else:
            break
    if x:
        print('NO')
    else:
        print('YES')


t=int(input())
for _ in range(t):
    solve()
