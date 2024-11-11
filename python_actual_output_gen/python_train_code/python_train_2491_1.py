t=int(input())
for i in range(t):
    a,b,c,n=map(int,input().split())
    l=[a,b,c]
    l.sort()
    m=(l[-1]-l[-2])+(l[-1]-l[-3])
    if m<=n and n%3==0:
        print('YES')
    else:
        print('NO')