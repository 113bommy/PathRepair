from math import factorial as fac
s=input()
s1=input()
mov=0
for i in range(len(s)):
    if(s[i]=='+'):
        mov+=1
    else:
        mov-=1
tap=0
count=0
for i in range(len(s1)):
    if(s1[i]=='+'):
        tap+=1
    elif(s1[i]=='-'):
        tap-=1
    else:
        count+=1

mov=mov-tap
if((count+mov)%2==1):
    print(0)
    exit()
else:
    a=(count+mov)//2
    b=count-a
    if(b<0 or a<0):
        print(0)
        exit()
    else:
        x=fac(a+b)//(fac(a))*fac(b)
        print(x/pow(2,a+b))

        
    
