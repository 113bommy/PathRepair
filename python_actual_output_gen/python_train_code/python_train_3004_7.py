N,M=map(int,input().split())
A=list(map(int,input().split()))
b=0
for a in A:
    if a>=1/(4*M):
        b+=1
print("Yes" if b>=M else "No")