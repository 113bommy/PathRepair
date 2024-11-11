def calc(s,x,y):
    ps=s[x:y:1]
    
    ss=s[0:x:1]
   # print(x,ps,ss)
    t=ss
    if((y-x)%2!=0):
        ss=ss[::-1]
    sf=ps+ss
    print(x,ps,t,ss,sf)
    return(sf)
        
 
for _ in range(int(input())):
    n=int(input())
    s=str(input())
    s1=s
    k=1
    for i in range(1,n+1):
        ts=calc(s,i,n)
        print(ts)
        if(ts<s1):
            s1=ts
            k=i+1
    print(s1)
    print(k)