for i in range(int(input())):
    t=int(input())
    flag=0
    if (t%3==0 or t%7==0):
        print ("YES")
 
    else:
        for a in range(1,101):
            for b in range(1,101):
                #print (a,b)
                if t%(3*a+7*b)==0:
#                    print (a,b)
                    print ("YES")
                    flag=1
                    break
            if (flag==1):
                break    
        if flag==0:
            print ("NO")