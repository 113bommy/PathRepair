n,k=map(int,input().split())
s=input()
if(k==1):
    for i in range(n):
        print("PRINT",s[i])
        if(i!=(n-1)):
            print("RIGHT")
    exit()
if(k==n):
    for i in range(-1,-n-1,-1):
        print("PRINT",s[i])
        if(i!=-n):
            print("LEFT")
    exit()
if((n-k)<k):
    for j in range(n-k):
        print("RIGHT")
    for i in range(-1,-n-1,-1):
        print("PRINT",s[i])
        if(i!=-n):
            print("LEFT")
else:
    for j in range(k-1):
        print("LEFT")
    for i in range(n):
        print("PRINT",s[i])
        if(i!=(n-1)):
            print("RIGHT")