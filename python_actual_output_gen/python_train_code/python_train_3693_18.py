n=input()[::-1]
for x in n:
    if int(x)<5:
        print("O-|","O"*int(x),"-","O"*(4-int(x)),sep="")

    elif int(x)>5:
        print("-O|","O"*(int(x)-5),"-","O"*(4-(int(x)-5)),sep="")
        
