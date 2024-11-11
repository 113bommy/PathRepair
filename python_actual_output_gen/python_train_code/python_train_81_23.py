for _ in range(int(input())):
    a,b,n=map(int,input().split())
    if(n%3==0):
        print(a)
    elif(n%3==1):
        print(a)
    elif(n%3==2):
        print(a^b)