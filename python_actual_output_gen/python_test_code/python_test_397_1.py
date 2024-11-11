n=int(input())
A=list(map(int,input().split()))
A.append(0)
B=[]
z=0
k=1
for i in range (1,n+1):
    if A[i]==A[i-1]:
        k+=1
    else:
        B.append(k)
        k=1
n-=B[0]
for i in range (1,len(B)):
    a=B[i]-B[i-1]
    if a>=0:
        if a>=z:
            n-=a-z
            z=0
        else:
            n-=0
            z-=a         
    else:
        n-=0
        z+=abs(a)
            
print(n)