n=int(input())
for a in range(n):
    L=list(map(int,input().split()))
    if(L[0]==L[2]):
        print(L[0],L[2]+1)
    else:
        print(L[0],L[2])
