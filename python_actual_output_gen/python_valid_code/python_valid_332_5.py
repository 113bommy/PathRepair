
a,b=(map(int,input().strip().split(' ')))
diff=b-a
if(diff>=5):
    print(0)
elif(diff==4):
    q=(a+1)%10
    w=(a+2)%10
    e=(a+3)%10
    f=(a+4)%10
    print((q*w*e*f)%10)
elif(diff==3):
    q=(a+1)%10
    w=(a+2)%10
    e=(a+3)%10
    print((q*w*e)%10)
elif(diff==2):
    q=(a+1)%10
    w=(a+2)%10
    
    print((q*w)%10)
elif(diff==1):
    q=(a+1)%10
    
    print((q)%10)
else:
    print(0)

