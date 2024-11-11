import sys

n=int(input())
A=list(map(int,input().split()))

if A==sorted(A):
    print(n)
    sys.exit()

if A[:n//2]==sorted(A[:n//2]) or A[n//2:]==sorted(A[n//2:]):
    print(n//2)
    sys.exit()

if A[:n//4]==sorted(A[:n//4]) or A[n//4:n//2]==sorted(A[n//4:n//2]) or A[n//2:n//4*3]==sorted(A[n//2:n//4*3]) or A[n//4*3:]==sorted(A[n//4*3:]):
    print(n//4)
    sys.exit()

if A[:n//8]==sorted(A[:n//8]) or A[n//8:n//4]==sorted(A[n//8:n//4]) or A[n//4:n//8*3]==sorted(A[n//4:n//8*3]) or A[n//8*3:n//2]==sorted(A[n//8*3:n//2]):
    print(n//4)
    sys.exit()

if A[n//2:n//8*5]==sorted(A[n//2:n//8*5]) or A[n//8*5:n//4*3]==sorted(A[n//8*5:n//4*3]) or A[n//4*3:n//8*7]==sorted(A[n//4*3:n//8*7]) or A[n//8*7:]==sorted(A[n//8*7:]):
    print(n//4)
    sys.exit()

print(1)
