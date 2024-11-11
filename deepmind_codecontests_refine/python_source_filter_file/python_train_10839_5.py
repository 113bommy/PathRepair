for _ in range(int(input())):
    a , b , k = map(int,input().split())
    if k%2==0:
        print(int(a*(k/2)-b*(k/2)))
    else:
        print(int(a*((k//2)+1)-b*(k//2)))
