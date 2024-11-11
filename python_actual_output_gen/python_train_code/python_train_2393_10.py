n,m=map(int,input().split())
c=0

while(n>0 and m>0):

    if(n==1 and m==1):
        break

    elif(n<m or n==m):
        n=n-1
        m=m-2
    elif(n>m):
        n=n-2
        m=m-2
    
    c=c+1
print(c)
