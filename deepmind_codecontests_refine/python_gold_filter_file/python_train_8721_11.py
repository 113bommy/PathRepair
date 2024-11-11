N,M=map(int,input().split())
A=list(map(int,input().split()))
S=sum(A)
c=0
for i in A:
    if S<=i*4*M:
        c+=1
print("Yes" if c>=M else "No")