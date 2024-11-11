n=int(input())
for i in range(n):
    a=int(input())
    if(a==0):
        print("Y "+str(0)+" "+str(0))
    elif(a<5 and a>0):
        print("N")
    else:
        print("Y "+str((a+((a**2-4*a)**0.5))/2)+" "+str((a-((a**2-4*a)**0.5))/2))