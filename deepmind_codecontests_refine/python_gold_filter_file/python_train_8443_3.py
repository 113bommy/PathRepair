n=int(input())
A=[]
for i in range(n):
    A+=[list(map(int,input().split()))]

cost=10**18
I=0
for i in range(n):
    ans=True    
    for j in range(n):
        if(A[i][0]<A[j][0] and A[i][1]<A[j][1] and A[i][2]<A[j][2]):
            ans=False
    
    if(ans):        
        cost=min(cost,A[i][3])
        if(cost==A[i][3]):
            I=i+1
       
print(I)        
        
