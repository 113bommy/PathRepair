N,M=map(int,input().split())
x=max(N//0.08+1,M//0.1+1)
y=min((N+1)/0.08, (M+1)/0.1)
print( -1 if y<x else int(x))