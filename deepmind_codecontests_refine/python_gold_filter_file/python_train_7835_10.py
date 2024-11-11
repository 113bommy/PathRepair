
for i in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if sum(a)==0:
        print('NO')
    else:
        if sum(a)>0:
            a.sort()
            a=a[::-1]
            print('YES')
            print(*a)
        else:
            print('YES')
            a.sort()
            print(*a)