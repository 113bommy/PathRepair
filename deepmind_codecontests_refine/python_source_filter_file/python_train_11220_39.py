N=int(input())
S=list(map(int,input().split()))
D=sorted(S)
A=1

for i in range(1,N):
    A=A*D[i-1]
    if A>=10**18:
        A=-1
        break
print(A)