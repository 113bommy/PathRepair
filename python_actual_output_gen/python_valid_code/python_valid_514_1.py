t=int(input())
for i in range(t):
    n=int(input())
    if(n==1):
        print(0)
    elif(n<10):
        print(1)
    else:
        n=str(n)
        if(n[len(n)-1]=="9"):
            print(int(n[:len(n)-1])+1)
        else:
            print(n[:len(n)-1])
