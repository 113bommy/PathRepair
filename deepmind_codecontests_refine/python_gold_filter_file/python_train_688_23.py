n=int(input())
A=[]
a=0
b=1
if(n==1):
    A.append(1)
else:
    for i in range(2,n+2):
        c=a+b
        A.append(c)
        a=b 
        b=c
for i in range(1,n+1):
    if(i in A):
        print("O",end='')
    else:
        print("o",end='')
