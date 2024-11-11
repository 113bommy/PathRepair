def answer(n,A):
    mini=10**9
    index=-1
    for i in range(n):
        if A[i]>=0:
            A[i]=-A[i]-1
            
        if  A[i]<mini:
            mini=A[i]
            index=i
            
        
    if n%2!=0:
        A[index]=-A[index]-1
    return A 

n=int(input())
arr=list(map(int,input().split()))
print(*answer(n,arr))