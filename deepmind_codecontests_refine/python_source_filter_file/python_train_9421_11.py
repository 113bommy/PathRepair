n = int(input())
m = n**2
L = [list(map(int, input().split())) for _ in range(m)]
H = [ 0 for _ in range(n)]
V = [ 0 for _ in range(n)]
R = ""
for k in range(m):
    i = L[k][0]-1
    j = L[k][1]-1
    if H[i] == 0 and V[j] == 0:
        H[i] = 1
        V[i] = 1
        R = R + str(k+1) + ' '
print(R)