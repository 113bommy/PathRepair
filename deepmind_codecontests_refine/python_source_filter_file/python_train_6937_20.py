n,p,l,r=map(int,input().split())
s=0
if (l<=p<=r):
    if(l>1 and (n-r)>0):
        if((r-p)<=(p-l)):
            s=r-p+1+r-l+1
        else:
            s=p-l+1+r-l+1
        print(s)
    else:
        if(l==1 and r!=n):
            print(r-p+1)
        elif(l==1 and r==n):
            print(0)
        else:
            print(p-l+1)
else:
    if(p<l):
        s=s+l-p+1
        if(r==n):
            print(s)
        else:
            print(s+n-l+1)
    else:
        s=s+p-r+1
        if(l==1):
            print(s)
        else:
            print(s+r-l+1)
            
            
        
        
        
