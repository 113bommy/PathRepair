n=int(input())
if n%2!=0:
    print (1)
else:
    if (n%5==1):
        print (14)
    elif(n%5==2):
        print (12)
    elif (n%5==3):
        print (8)
    elif (n%5==4):
        print (1)
    else:
        z=1
        while (True):
            if int((n*z+1)**0.5)**2==(n*z+1):
                print (z)
                break
            z+=1