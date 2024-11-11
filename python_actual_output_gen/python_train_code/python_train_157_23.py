for _ in range(int(input())):
    a,b = map(int,input().split())
    c=0
    if(min(a,b)==0):
        print(0)
    elif(max(a,b)>=2*min(a,b)):
        print(min(a,b))
    else:
        print((a+b)/3)
