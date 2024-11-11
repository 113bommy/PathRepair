n, m =  map(int , input().split())
s=0
if(n>m):
    print(n-m)
else:
    while(n!=m):
        if(m%2==0 and m/2>n/2):
            m=m/2
       
        else:
            m=m+1
        s=s+1
        
    print(s)