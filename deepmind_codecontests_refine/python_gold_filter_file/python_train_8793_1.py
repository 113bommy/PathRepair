m,n=map(int,input().split())
s=0
if  n<=m:
    print(m-n)
else:
    while n!=m:
        if m>n:
            n+=1
        elif n%2!=0:
            n+=1
        else:
            n/=2
        s+=1
    print(s)
        
#倒推法！！
        
       
    

              
