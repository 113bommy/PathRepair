for t in range(int(input())):
    n=int(input())
    c1=0
    c2=0
    k=n%3
    p=(n-k)//3
    c1=p
    c2=p
    if(k==1):
        c1+=1
    elif(k==2):
        c2+=1
    print(c1,c2)
