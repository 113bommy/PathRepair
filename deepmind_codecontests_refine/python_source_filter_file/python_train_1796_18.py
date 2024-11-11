import math
r1 = lambda : int(input());
rm = lambda : map(int,input().split());
rls = lambda : list(rm())


test = r1()
while(test):
    test-=1;
    n,k=rm();
    flag =True;
    if((n%2==0 and k==n-1) or (n<k) or (n%2==0 and k%2==1 and n<(2*k) )):
        flag = False;
        
    if(k%2==0 and n%2==1):
        flag = False;
    x=k-1;
    ans=[];
    if(n%2==0 and k%2==1):
        m=k-1;
        ans=[2]*m;
        x=n-(2*m);
        ans.append(x);
    elif(n%2==1 or k%2==1 or (n%2==0 and k%2==0 and n<(2*k))):
        ans=[1]*x;
        x=n-x;
        ans.append(x);
    elif(n%2==0 and k%2==0):
        m=k-1;
        ans=[2]*m;
        x=n-(2*m);
        ans.append(x);
    
        
    if(flag):
        print("YES");
        print(*ans);
    else:
        print("NO")