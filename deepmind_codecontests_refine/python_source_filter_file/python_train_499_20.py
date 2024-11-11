A,B,C,X,Y=map(int,input().split())

A=10**9
for i in range(0,10**5+1):
    S=i*2*C+max(0,X-i)*A+max(0,Y-i)*B
    A=min(A,S)
print(A)