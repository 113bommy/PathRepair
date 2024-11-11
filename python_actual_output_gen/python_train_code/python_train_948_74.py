n=int(input())
if(n==1 or n==2):
    print("1")
elif(n==3):
    print("0")
else:
    if(n%4==0):
        print("0")
    elif(n%4==1 or n%4==2):
        print("1")
    elif(n%4==3):
        print("2")
    
    
    