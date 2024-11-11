t = int(input())
for i in range(t):
    a,b=map(int,input().split())
    if a-b>1:
        print('YES')
    else:
        print('NO')