n=int(input())
if(n%2==0):
    m=n//2+1
else:
    m=(n+1)//2
if(n==1):
    print(1)
    print(1,1)
else:    
    print(m)
    for i in range(m):
        print(1,i+1)
    for j in range(n-m):
        print(j+2,m)