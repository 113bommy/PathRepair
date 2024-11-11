for _ in range(int(input())):
    n=int(input())
    if n==1:
        print(-1)
    else:
        if (n-1)%3==0:
            print('2'*(n-2)+'33')
        else:
            print('2'*(n-1)+'3')