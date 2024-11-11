for _ in range(int(input())):
    A,B = map(int,input().split())
    k = 0
    b = 9
    chk = True
    while(chk):
        n = len(str(b))
        if b + 1 == 10 ** n and b <= B:
            k+=1
            b = int(str(b) + '9')
        else: 
            chk = False
    print(k*(A))