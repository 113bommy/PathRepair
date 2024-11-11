A,B,C,K=map(int,input().split())

if A>=K:print(K)
elif A+B>=K:print(K)
else: print(A-(K-(B+A)))