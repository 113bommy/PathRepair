import sys
N = int(input())
A = [int(input()) for i in range(N)]

if A[0]!=0:
    print(-1)
    sys.exit()
for i in range(N-1):
    if A[i+1]-A[i]>1:
        print(-1)
        sys.exit()

num = 0
for i in range(N-1):
    if A[i]>=A[i+1]:
        num += A[i]
num += A[-1]
print(num)