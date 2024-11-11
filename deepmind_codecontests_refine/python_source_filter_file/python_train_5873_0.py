import sys
def Z(s):
    return int(s)-1

n=int(sys.stdin.readline())

Hotels=[False]*(n)

Rep=[0]*(n)
Chains=[]

Type=list(map(int,sys.stdin.readline().split()))
for i in range(n):
    if(Type[i]==1):
        Hotels[i]=True
A=list(map(Z,sys.stdin.readline().split()))

for item in A:
    Rep[item]+=1
for i in range(n):
    if(Hotels[i]):
        Chains.append([i])
        x=A[i]
        if(x==-1):
            continue
        while(A[x]!=-1 and Rep[x]<=1):
            Chains[-1].append(x)
            x=A[x]
        if(Rep[x]<=1):
            Chains[-1].append(x)


    
        
if(n==1):
    print(1)
    print(1)
else:
        
    X=max(Chains,key=len)



    sys.stdout.write(str(len(X))+"\n")
    sys.stdout.write(str(X[-1]+1))

    for i in range(len(X)-2,-1,-1):
        sys.stdout.write(" "+str(X[i]+1))       
        
