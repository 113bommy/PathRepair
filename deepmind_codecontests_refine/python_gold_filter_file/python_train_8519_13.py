import sys
input = sys.stdin.readline
N=int(input())
A=[int(i) for i in input().split()]
A.sort()
K=A[0]
x=0
y=0
for i in range(N):
    if A[i]!=K and A[i]!=K+1:
        print('No')
        sys.exit()
    if A[i]==K:
        x+=1
    elif A[i]==K+1:
        y+=1

if x==N and x >=2*K:
    print('Yes')
    sys.exit()
if x==N and N==K+1:
    print('Yes')
    sys.exit()
if x<=K and y>=(K-x+1)*2:
    print('Yes')
    sys.exit()
print('No')