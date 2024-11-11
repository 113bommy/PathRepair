n=int(input())

A=[0]+list(map(int,input().split()))

for i in reversed(range(1,n+1)):
    if sum(A[::i])%2!=A[i]:
        A[i]=1
        
print(sum(A))
if sum(A)!=0:
    for i,a in enumerate(A):
        if a==1:
            print(i)