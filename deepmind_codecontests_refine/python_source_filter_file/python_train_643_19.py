import sys
input = sys.stdin.buffer.readline

n , Sx , Sy = [int(i) for i in input().split()]
Q1 =  Q2 =  Q3 = Q4 = N = E = S = W = 0
for i in range(n):
    x,y = [int(i) for i in input().split()]
    rel_x = x - Sx ; rel_y = x - Sy
    if  y == Sy: 
        if rel_x > 0: E += 1
        else:         W += 1
    elif x == Sx:
        if rel_y > 0: N += 1
        else:         S += 1
    else:
        if   rel_x > 0 and rel_y > 0: Q1 += 1
        elif rel_x < 0 and rel_y > 0: Q2 += 1
        elif rel_x < 0 and rel_y < 0: Q3 += 1
        else:                         Q4 += 1

U = Q1 + Q2 + N
D = Q3 + Q4 + S
R = Q1 + Q4 + E
L = Q2 + Q3 + W
ans = max(U,D,R,L)
px = py = 0
print(ans)
if   ans == U:
    px = Sx     ; py = Sy + 1
elif ans == D:
    px = Sx     ; py = Sy - 1
elif ans == R:
    px = Sx + 1 ; py = Sy
else:
    px = Sx - 1 ; py = Sy
print(str(px) + ' ' + str(py))
