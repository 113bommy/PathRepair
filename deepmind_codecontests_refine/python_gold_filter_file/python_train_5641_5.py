# cook your dish here
t=int(input())
while(t):
    t=t-1
    ans=0
    b,p,f=map(int,input().split(' '))
    h,c=map(int,input().split(' '))
    buns=b//2
    if(buns>=(p+f)):
        ans=p*h + f*c
    elif(buns>=1):
        if(c>=h):
            ans=f*c+(buns-f)*h  
            if(buns<f):
                ans=buns*c
        else:
            ans=p*h+(buns-p)*c
            if(buns<p):
                ans=buns*h
    print(ans)  