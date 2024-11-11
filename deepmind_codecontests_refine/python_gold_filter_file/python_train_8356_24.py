 
for _ in range(int(input())):
    r = int(input())
    t,f,s=0,0,0;
    tol=0;
    flag=False;
    for n in range(0,99999):
        t=n%10
        f=(n%100)//10
        s=n//100
        tol= 3*t+f*5+s*7
        if(tol==r):
            print(t,f,s)
            flag=True;
            break;
 
    if (not flag):
        print(-1)