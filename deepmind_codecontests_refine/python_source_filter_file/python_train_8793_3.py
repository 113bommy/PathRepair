m,n=map(int,input().split())
s=0
if  n<=m:
    print(m-n)
else:
    while n!=m:
        if m<n:
            m+=1
        elif m%2!=0:
            m+=1
        else:
            m/=2
        s+=1
    print(s)
        
#倒推法！！
        
       
    

              
