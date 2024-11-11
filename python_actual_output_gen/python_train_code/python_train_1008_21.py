n=int (input())
A=[int(x) for x in input().split()]
for i in range (1,int((n+1)/2)):
        if i&1:
                u=A[i-1]
                A[i-1]=A[n-i]
                A[n-i]=u
for i in A:
        print(i,end=' ')
        
