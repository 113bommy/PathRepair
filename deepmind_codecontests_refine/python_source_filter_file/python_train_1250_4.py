def partition(A,p,r):
    x=A[r]
    i=p-1
    for j in range(p,r):
        if A[j]<x:
            i+=1
            A[i],A[j]=A[j],A[i]
    A[i+1],A[r]=A[r],A[i+1]
    return i+1

n=int(input())
A=list(map(int,input().split()))
k=partition(A,0,len(A)-1)
front=" ".join(map(str,A[:k]))
back=" ".join(map(str,A[k+1:]))
ans=front+" ["+str(A[k])+"] "+back
print(ans)
