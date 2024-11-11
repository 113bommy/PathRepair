b=[]
f=0
g=0
for r in range(0,8):
    c=input()
    for i in c:
        if(i=="Q"):
            f=f+9
        elif(i=="R"):
            f+=5
        elif(i=="B"):
            f+=3
        elif(i=="K"):
            f+=3
        elif(i=="P"):
            f+=1
        elif(i=="q"):
            g+=9
        elif(i=="r"):
            g+=5
        elif(i=="b"):
            g+=3
        elif(i=="k"):
            g+=3
        elif(i=="p"):
            g+=1
if(f==g):
    print("Draw")
elif(f>g):
    print("White")
elif(g>f):
    print("Black")



   




   
