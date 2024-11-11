for i in range(int(input())):
    a,b = [int(j) for j in input().split()]
    if((a+b)%3!=0 or abs(a-b)>min(a,b)):
        print('NO')
    else:
        print('YES')
