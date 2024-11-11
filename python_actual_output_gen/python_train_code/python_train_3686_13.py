for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if max([a,b,c])>=a+b+c-max([a,b,c])+1:print("Yes")
    else:print("No")
    
