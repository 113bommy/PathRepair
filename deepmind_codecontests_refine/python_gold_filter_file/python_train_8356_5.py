t = int(input())
for i in range(1,t+1):
    n=int(input())
    if ((n==1) or (n==2) or (n==4)):
        print(-1)
    else:
        if(n%3==0):
            print(int(n/3),0,0)
        elif(n%3==1):
            print(int((n-7)/3),0,1)
        else:
            print(int((n-5)/3),1,0)
    