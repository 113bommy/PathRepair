t=int(input())
for i in range(t):
    r,g,b,w=map(int,input().split())
    c1=r%2+g%2+b%2
    c=r%2+g%2+b%2+w%2
    if(c%2==0):
        if(c==0):
            print("Yes")
        elif(min(r,g,b)!=0 and w%2!=0 and c1==3):
            print("Yes")
        else:
            print("No")
    else:
        if(c==1):
            print("Yes")
        elif(c1==3 and w%2==0):
            print("Yes")
        elif(c1==2 and w%2==1 and min(r,g,b)!=0):
            print("Yes")
        else:
            print("No")
