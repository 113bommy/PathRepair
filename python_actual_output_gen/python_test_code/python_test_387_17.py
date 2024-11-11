n1=int(input())
a=int(n1/1234567)
b=int(n1/123456)
t=0
resultado=0
for x in range(0,a+1):
    for i in range(0,b+1):
        resultado=n1-(1234567*x+123456*i)
        if(resultado%1234==0 and resultado>0):
            print("YES")
            t=1
            break
    if(t==1):
        break
if(t==0):
    print("NO")
