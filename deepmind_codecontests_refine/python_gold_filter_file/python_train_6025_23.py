N,L=map(int,input().split())
A=list(map(int,input().split()))
x=-1
for i in range(N-1):
    if A[i]+A[i+1]>=L:
        x=i
        break
if x==-1:
    print('Impossible')
else:
    print('Possible')
    r=list(range(1,x+1))+list(range(N-1,x+1,-1))+[x+1,]
    print(*r,sep='\n')