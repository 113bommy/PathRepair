N, M =  map(int, input().split()) 
L = [0]*M
R = [0]*M

for m in range(M):
    L[m], R[m] = map(int, input().split())
    
print(max(0,min(R)-max(L)+1))