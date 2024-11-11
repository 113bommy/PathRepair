for _ in range(int(input())):
    n=int(input())
    m=n*4
    for i in range(n):
        print(m,end=" ")
        m-=2
    print()