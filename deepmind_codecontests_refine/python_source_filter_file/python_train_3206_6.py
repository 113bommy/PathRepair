A,B,K=map(int,input().split())
if A>K:
    print(A-K,B)
else:
    print(0,B-K+A)