read=input().split()
n=int(read[0])
m=int(read[1])
x=m+n
if(n==1 and m==1):
    print(0)
elif n==1 or m==1:
    if(n==1):
        for i in range (0,m):
            print(i+2,end=" ")
    else:
        for i in range (0,n):
            print(i+2,end='')

else:
    for i in range(0,n):
        for j in range (0,m):
             print(x*(j+1),end=" ")
        print('')
        x=x-1