t=int(input())
for i in range(t):
    s="";
    n=int(input())
    k=(3*n)/4;
    for i in range(int(k)):
        s+="9";
    if(n%4!=0):
        s+="8";
    for i in range(int(n/4)):
        s+="8";
    print(int(s),end='\n')
     
    