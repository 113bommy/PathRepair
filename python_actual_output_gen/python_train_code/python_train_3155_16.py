for i in range(int(input())):
    a,b,c,d=list(map(int,input().split(' ')))
    if abs(a-c)==0 or abs(b-d)==0:
        print(abs(a-c)+abs(b-d))
    else:
        print(abs(a-c)+abs(b-d)+3)
    
