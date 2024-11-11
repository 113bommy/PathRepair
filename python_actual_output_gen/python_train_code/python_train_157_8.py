n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    if(a==0 or b==0):
        print(0)  
    elif(a>b and a>0 and b>0):
        if(int(a/b)<3):
            print(int((a+b)/3))   
        else:
            print(b)
    elif(b>a and a>0 and b>0):
        if(int(b/a)<3):
            print(int((a+b)/3))
        else:
            print(a) 
    else:
        print(int((a+b)/3))        