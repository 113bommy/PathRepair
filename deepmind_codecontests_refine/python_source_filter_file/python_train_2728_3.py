for _ in range(int(input())):
    n =  int(input())
    l = list(map(int,input().split()))
    for i in range(n-1):
        if abs(l[i]-l[i+1]) > 2:
            print('YES')
            print(i,i+1)
            break
    else:
        print('NO')
