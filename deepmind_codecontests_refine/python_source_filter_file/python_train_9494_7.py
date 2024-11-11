from sys import stdin
inp = lambda : stdin.readline().strip()


t = int(inp())

for _ in range(t):
    n = int(inp())
    a, b, c = [int(x) for x in inp().split()]
    st = inp()
    r = 0
    p = 0
    s = 0
    for i in st:
        if i == 'R':
            r += 1
        if i == 'P':
            p+=1
        if i == 'S':
            s+=1
    wins = min(a,s) + min(b,r) + min(c,p)
    if wins >= (n+1)//2:
        print('YES')
        ans = [0]*n
        for i in range(n):
            if st[i] == 'R' and b > 0:
                ans[i] = ('P')
                b -= 1
            if st[i] == 'P' and s > 0:
                ans[i] = ('S')
                s -= 1
            if st[i] == 'S' and r > 0:
                ans[i] = ('R')
                r-=1
        for i in range(n):
            if ans[i] == 0:
                if a>0:
                    ans[i] = ('R')
                    a-=1
                elif b > 0:
                    ans[i] = ('P')
                    b-=1
                else:
                    ans[i] = ('S')
                    c-=1
        print(''.join(ans))
    else:
        print('NO')