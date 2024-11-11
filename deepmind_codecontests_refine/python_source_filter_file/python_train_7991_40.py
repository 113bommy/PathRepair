from math import floor

m=1
M=10**9+1

N,K=map(int,input().split())
A=list(map(int,input().split()))

def OK(p):
    if sum([(a-1)//p for a in A])<=K:
        return True
    else:
        return False

while M-m>1:
    p=(m+M)//2
    if OK(p):
        M=p
    else:
        m=p
print(M)