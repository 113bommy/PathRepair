def f(a):
    r=0
    if(a==0):
        return 0
    elif(a<10):
        return a*10
    elif(a>=10):
        r=(a%10)*10+(a//10)
        return r
        

x,y=input().split(':')
a=int(x)
b=int(y)
ans=0
if((a<6 and b<=f(a)) or (a>9 and b<=f(a))):
    ans=f(a)-b
elif(a<5 or a>9):
    ans=60-b+f(a+1)
if(a>=5 and a<=9):
    ans=60-b+(10-(a+1))*60+1
if(a==23 and b>f(a)):
    ans=60-b
if((a>15 and a<20) or (a==15 and b>f(a))):
    ans=60-b+(20-(a+1))*60+2
print(ans)
    
    
        
        

            
    

    
    