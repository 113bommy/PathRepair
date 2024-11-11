for _ in range(int(input())):
    a=int(input())+int(input())
    print([a,'overflow'][a>10**80])