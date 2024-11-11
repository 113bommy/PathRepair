s=int(input())
for i in range(s):
    p=int(input())
    if p==1 or p==2 or p==4:
        print(-1)
    else:
        if p%3==0:
            a=p//3
            print(str(a) +" 0" +" 0")
        elif p%5==0:
            a=p//5
            print("0 "+str(a)+ " 0")
        elif p%7==0:
            a=p//7
            print("0"+ " 0 "+str(a))
        elif (p-7)%3==0:
            a=(p-7)//3
            print(str(a)+ " 0"+ " 1")
        elif (p-7)%5==0:
            a=(p-7)//5
            print("0 "+str(a)+ " 1")    
        elif (p-5)%3==0:
            a=(p-5)//3
            print(str(a) +" 1" +" 0") 
        elif (p-5)%7==0:
            a=(p-5)//7
            print("0"+ " 1 "+str(a))       
        elif (p-3)%5==0:
            a=(p-3)//5
            print("1 "+str(a)+ " 0") 
        elif (p-3)%7==0:
            a=(p-3)//7
            print("1"+ " 0 "+str(a)) 
        else:
            print(-1)