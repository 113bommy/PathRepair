t=input()
while True:
    try:
        t=int(t)
        if (t>0) and (t<180):
            break
        else:
            t=input()
            
    except ValueError:
            print()


for i in range(t):
    a=int(input())


##    A=(n-2)*180)/n
    #x is num sides
    #a is angles

    x=-360/(a-180)
    remainder=-360%(a-180)
   
   
    if 0<a<180 and remainder==0:
        print("YES")
    else:
        print("NO")
    

