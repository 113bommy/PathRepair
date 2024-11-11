s=input()
Cap=Sma=Sym=Num=0
if(len(s)<5):
    print("Too weak")
else:
    for i in s:
        d=ord(i)
        if(d>=65 and d<=90):
            Cap+=1
        elif(d>=97 and d<=122):
            Sma+=1
        elif(d>=48 and d<=57):
            Num+=1
        else:
            Sym+=1
           
    if(Cap>0 and Sma>0 and Num>0 and Sym>0):
        print("Correct")
    else:
        print("Too weak")

#CONTEST_is_STARTED!!11