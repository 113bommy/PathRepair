for _ in range(int(input())):
    c,d=map(int,input().split())
    if(c==0 and d==0):
        print(0)
    elif(abs(c-d)==1):
        print(-1) 
    elif(abs(c-d)==0):
        print(1)
    elif(abs(c-d)%2==0):
        print(2)
        