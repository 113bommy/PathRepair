L=list(map(int,input().split()))
K=int(input())
N=sorted(L)
print(N[0]+N[1]+N[2]*(2**K))