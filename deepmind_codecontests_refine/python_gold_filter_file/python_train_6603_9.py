def Contador(A,l):
    cont=0
    for i in range(len(A)):
        if A[i]==l:
            cont+=1
    return cont
n=int(input())
a=input()
antX=a[0]
antNX=a[1]
c=0
if a[0]==a[n-1] and Contador(a,antNX)==n-2:
    c+=1
    for i in range(1,n):    
        a=input()
        if i==n-1-i:
            if  antX==a[i] and Contador(a,antNX)==n-1:
                c+=1    
        else:
            if a[i]==a[n-1-i] and antX==a[i] and Contador(a,antNX)==n-2:
                c+=1

if c==n:
    print("YES")
else:
    print("NO")