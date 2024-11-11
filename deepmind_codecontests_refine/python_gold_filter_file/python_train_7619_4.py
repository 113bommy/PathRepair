import sys
n,m = map(int,input().split())
M = []
for i in range(n):
    M += [list(map(int,input().split()))]
S = M[-1][-1]

for j in range(n-2 , -1 , -1):   
    if M[j][-1] >= M[j+1][-1] :
        print(-1)
        sys.exit()
    if M[j][-1] == 0:
        M[j][-1] = M[j-1][-1] - 1  
    S += M[j][-1]
    
for j in range(m-2 , -1 , -1):
    if M[-1][j] >= M[-1][j+1] :
        print(-1)
        sys.exit()
    if M[-1][j] == 0:
        M[-1][j] = M[-1][j-1] - 1   
    S += M[-1][j]
        
for k in range(m-2 , -1 , -1):
    for p in range(n-2 , -1 , -1):
        if M[p][k] >= min(M[p+1][k] , M[p][k+1]):
            print(-1)
            sys.exit()
        if M[p][k] == 0:
            M[p][k] = min(M[p+1][k] , M[p][k+1]) - 1 
        S += M[p][k]
print(S)