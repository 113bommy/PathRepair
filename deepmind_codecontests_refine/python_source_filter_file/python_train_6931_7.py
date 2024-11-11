p=10**5+2
def Sieve():
    l=[True]*p 
    i=2 
    while i*i<=p:
        if l[i]:
            for j in range(2*i,p,i):
                l[j]=False
        i+=1 
    return l 
isprime=Sieve()
n=int(input())
if n==1:
    print(1)
    print(1)
elif n==2:
    print(1)
    print(1)
else:
    print(2)
    for i in range(2,n+2):
        if isprime[i]:
            print(1,end=' ')
        else:
            print(2,end=' ')
    