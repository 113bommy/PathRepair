import sys
N,L=map(int,input().split())
A=[int(i) for i in input().split()]
s=10**23
for i in range(N-1):
    if A[i]+A[i+1]>=L:
        s=i
        break
if s==10**23:
    print('Impossible')
    sys.exit()
print('Possible')
L=[]
for i in range(s):
    L.append(i+1)
for i in range(N-2,s,-1):
    L.append(i+1)
L.append(s+1)
#print(L,s)
print('\n'.join(map(str,L)))