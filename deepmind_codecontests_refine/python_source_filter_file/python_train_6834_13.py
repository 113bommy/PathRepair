n = int(input())
if(n>37):
    print("-1")
else :
    if(n%2==0):
        print("8"*(n//2))
    else :
        print("8"*(n//2),"4",sep="")
