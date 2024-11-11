n=int(input())
s=input()
a=[]

if n%2==0:
    k=n//2
    
    for i in range(-k,k+1):
        a.append(i)
    
    print(len(a))
else :
    k=n//2
    for i in range(-k,k+1):
        a.append(i)
    print(len(a))
