n=int(input())
for i in range(n+1):
    for j in range(n+1):
        if i+j>=n:
            if j==n and i==0:
                print(str(i+j-n)+"", end="")
            else:
                print(str(i+j-n)+" ", end="")
        else:
            print("  ",end="")
    for j in range(n+1):
        if i-j>1:
            print(str(i-j-1)+" ",end="")
        elif i-j==1:
            print(str(i-j-1)+"",end="")
    print()
for i in range(n-1,-1,-1):
    for j in range(n+1):
        if i+j>=n:
            if i==0 and j==n:
                print(str(i+j-n)+" ", end="")
            else:
                print(str(i+j-n)+" ", end="")
        else:
            print("  ",end="")
    for j in range(n+1):
        if i-j>1:
            print(str(i-j-1)+" ",end="")
        elif i-j==1:
            print(str(i-j-1)+"",end="")
    print()
