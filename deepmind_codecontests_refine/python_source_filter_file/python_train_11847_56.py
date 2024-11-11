N, A, B = map(int, input().split())
C=B-A
D=min(A-1,N-B)+1 + (B - A - 1)/2
if C%2==1:
    print (D)
else:
    print(C/2)