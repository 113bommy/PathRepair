for T in range(int(input())):
    n=int(input())
    c=0
    d=0
    l=list(map(int,input().split()))
    for i in range(len(l)):
        if(i%2==0 and l[i]%2!=0):
            c+=1
        elif(i%2!=0 and l[i]%2==0):
            d+=1
    if(c==d):
        print(c)
    elif(c==0 and d==0):
        print("0")
    elif(d!=c):
        print(-1)
