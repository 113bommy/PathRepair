a,b,c=input().split()
a=int(a)
b=int(b)
c=int(c)
cnt=0
while(c>0):
    g=1
    for i in range(1,a):
        if(a%i==0):
            if(c%i==0):
                if(i>g):
                    g=i
    c=c-g
    if(c==0):
        print("0")
        break
    g=1
    for i in range(1,b):
        if(b%i==0):
            if(c%i==0):
                if(i>g):
                    g=i
    c=c-g
    if(c==0):
        print("1")

    
