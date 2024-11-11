for i in range(int(input())):
    a,b=map(int,input().split())
    k=a%b
    if(k==0):
        print(0)
    else:
        print(b-k)