a=int(input())
if (a%10==0):
    print(a)
elif (a%10<=5):
    a=a/10
    r=int(a*10)
    print(r)
else:
    a=a/10
    q=int(a)
    q=q+1
    b=int(q*10)
    print(b)
    
