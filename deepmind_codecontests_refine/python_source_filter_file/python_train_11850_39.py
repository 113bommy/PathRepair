N,M=map(int,input().split())

for g in range(M//N,0,-1):
    if (M-(N-1)*g)%g==0:
        break

print(g)