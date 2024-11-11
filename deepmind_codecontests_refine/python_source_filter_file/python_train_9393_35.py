# cook your dish here
t=int(input())
while(t):
    t=t-1
    n=int(input())
    if(n==1):
        print("-1")
    else:
        #for i in range(n*10,10**n):
        while(n-1):
            print("2",end="")
            n=n-1
        print("9")