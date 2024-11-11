for _ in range(int(input())):
    a,c=int(input()),1
    if(a%2==0):
        print(a//2)
    else:
        print((a+c)//2)
        c*=-1