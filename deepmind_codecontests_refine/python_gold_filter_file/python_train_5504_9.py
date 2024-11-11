for _ in range(int(input())):
    a=int(input())+int(input())
    print(['overflow',a][a<10**80])