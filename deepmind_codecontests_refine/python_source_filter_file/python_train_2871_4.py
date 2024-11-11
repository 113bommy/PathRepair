n=int(input())
L=[int(x) for x in input().split()]

if n%2==1:
    n+=1

for i in range(1,n//2,2):
    L[i-1],L[-1*i]=L[-1*i],L[i-1]

for x in L:
    print(x,end=" ")