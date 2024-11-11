n,m,x1,y1=map(int,input().split())
print(x1,y1)
k=1
while k<m+1:
    if k!=y1:
        print(x1,k)
    k+=1
   
i=1
ch=k-1
while i<n+1:
    if i!=n:
        #print(ch)
        if ch==1:
            
            j=1
            while j<m+1:
                print(i,j)
                j+=1
            ch=j-1
        else:
            j=m
            while j>0:
                print(i,j)
                j-=1
            ch=j+1
    
    i+=1