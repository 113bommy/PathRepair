import sys
N,L=map(int,input().split())
A=[int(i) for i in input().split()]
flag=True
a=-1
for i in range(N-1):
    if A[i+1]+A[i]>=L:
        flag=False
        a=i+1
        break
if flag:
    print('Impossible')
    sys.exit()
print('Possible')
for i in range(1,a):
    print(i)
for i in range(N-1,a,-1):
    print(i)
print(a)
