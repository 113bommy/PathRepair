n1,n2=map(int, input().split())
for i in range(1,n1+1):
    if i%2==1:
        print("#"*n1)  
    elif i%4==2:
        print("."*(n1-1),end='')
        print("#")
    elif i%4==0:
        print("#",end='')
        print("."*(n1-1))
      

