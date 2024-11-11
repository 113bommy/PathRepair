N,M = map(int,input().split())
A = list(map(int,input().split()))
A.sort()

if A[-M]/sum(A) < 1/(2*M) :
    print("No")
else:
    print("Yes")