n=int(input())-1
A=list(map(int,input().split()))
i=0
for j in range(n):
 if A[j]<=A[-1]:A[i],A[j]=A[j],A[i];i+=1
A[i],A[n]=A[n],A[i]
print(" ".join(map(str,A[:k]))+" ["+str(A[i])+"] "+" ".join(map(str,A[k+1:])))
