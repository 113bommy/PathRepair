def solve(n, m):
    h=m&-m
    for c in input():
        if c=='U' and m!=(n+1)>>1:
            m+= -h if (m+h)%(h<<2)==0 else h
            h<<=1
        if c in 'LR' and h>1:
            h>>=1
            m+= -h if c=='L' else h
    return m

n, m=map(int, input().split())
for _ in range(m):
    print(solve(n, int(input())))