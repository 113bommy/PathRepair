for _ in range(int(input())):
    nu=int(input())
    ar=list(map(int,input().split()))
    for i in range(nu):
        ar[i]=((-1)**(i&1))*ar[i]
    for i in ar:
        print(i,end=' ')
    print('')
