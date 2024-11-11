for _ in range(int(input())):
    n = int(input())
    if(n%3==0):
        print(n//3,0,0)
    elif(n%3==1 and n > 4): 
        print((n-7)//3,0,1)
    elif(n%3==2 and n > 2):
        print((n-5)//3,1,0)
    else :
        print(-1)