N,M=map(int,input().split())
A=list(map(int,input().split()))

if sorted(A,reverse=True)[M-1]>sum(A)/4/M:
    print("Yes")
else:
    print("No")