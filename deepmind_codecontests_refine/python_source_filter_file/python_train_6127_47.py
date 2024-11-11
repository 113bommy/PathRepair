n, m = map(int,input().split())
i = (m-2*n)//4
if i < 0:
    print(n)
else:
    print(n+i)
