n=input()[::-1]
for x in n:
    if int(x)<5:
        print("o-|","o"*int(x),"-","o"*(4-int(x)),sep="")

    elif int(x)>5:
        print("-o|","o"*(int(x)-5),"-","o"*(4-(int(x)-5)),sep="")
        
