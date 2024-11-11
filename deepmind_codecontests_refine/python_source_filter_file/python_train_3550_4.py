import sys
n = int(input())
A = [int(x) for x in input().split()]
m = int(input())
B = [int(x) for x in input().split()]

def debug(name, val):
    sys.stderr.write(name + '=' + str(val) + '\n')

S = A[0] - B[0]
i, j, k = 0, 0, 0
while((i < n-1 and j < m-1) or (i < n-1 and S < 0) or (j < m-1 and S > 0)):
    if(S < 0):
        i += 1
        S += A[i]
    elif(S > 0):
        j += 1
        S -= B[j]
    else:
        
        k += 1
        i += 1
        j += 1
        S = A[i] - B[j]

if(S == 0 and i == n and j == m):
    print(k+1)
else:
    print(-1)
